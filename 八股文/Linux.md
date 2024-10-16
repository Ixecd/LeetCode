# Linux常用知识

## Linux接收网络包的流程
1. 当网卡接收到一个网络包的时候,会通过DMA技术,将网络包写入到指定的内存地址(Ring Buffer),一个环形缓冲区,接着就告诉操作系统这个网络包已到达
2. 最简单的通知方式是触发中断,但是在高性能网络场景下,会触发非常多的中断,影响系统的整体效率
3. 为了解决频繁中断导致的性能问题,Linux2.6中引入了**NAPI机制**,混合中断和轮询的方式来接收网络包,核心是**首先采用中断唤醒数据接收的服务,之后poll的方法来轮询数据**
4. 触发硬件中断,当CPU接收到硬件中断的时候,根据中断表,调用已经注册的中断处理函数
5. 调用中断处理函数之前
    1. 先暂时屏蔽中断,表示已经知道内存中有数据了,告诉网卡下次再次受到数据包直接写进内存,不需要再通知CPU
    2. 发起软中断,执行完软中断对应的内核线程ksoftirqd,恢复刚才屏蔽的中断
6. 硬件中断处理函数的事情很少,主要耗时的工作都交给软中断处理函数

**软中断处理函数**
- 内核中**ksoftirqd线程**专门负责处理软中断,当这个线程接收到软中断之后,就会来轮询处理数据
- 这个线程会从**Ring Buffer**中获取一个数据帧**sk_buffer**,作为一个网络包交给网络协议栈进行逐层处理

## Linux发送网络包的流程刚好和上面相反
- sk_buff可以表示各个层地数据包,在应用层叫**data**,在传输层叫**segment**,在网络层叫**packet**,在数据链路层叫**frame**
- 为了避免各个层之间地拷贝,所以**sk_buff**中包括了所有属性,通过调整sk_buff中的**data**指针来实现,data指针创建一大块内存,之后不断往这块内存中添加即可,从tail向head添加,解包的时候就可以直接通过**data**指针从data向tail不断拆开即可
1. EPOLL监听文件描述符的EPOLLOUT事件,每个文件描述符背后都对应一个读缓冲区和一个写缓冲区
2. 监听到EPOLLOUT事件,之后触发对应的回调函数,使用write/send将用户数据以sk_buff的形式从用户态拷贝到内核态的写缓冲区中,之后通过操作系统的协议栈来一层一层封装,如果是TCP要拷贝留一份sk_buff,因为要支持丢失重传,之后做好一切封装之后发送到网卡的发送队列,之后触发软中断,通知网卡驱动程序有包发送,驱动程序就会从发送队列中读取sk_buff,并挂在Ring Buffer上,再映射到网卡可访问的DMA上,最后真实发送
3. 数据发送完之后,工作并没有结束,内存还没有被清理,发送完之后网卡设备会触发硬件中断来释放内存,主要释放sk_buff和清理Ring Buffer内存
4. 如果是TCP当收到ACK报文应答时,才会把传输层中拷贝的那一份sk_buff释放掉

## 发送网络数据的时候,涉及几次内存拷贝?
1. 调用write/send 将数据从用户态拷贝到socket_buffer内核态
2. 如果是TCP传输,在传输层要拷贝每一个sk_buff以支持丢失重传
3. 如果IP层发现sk_buff的大小大于MTU时,需要申请额外的sk_buff

1. 使用`route -n`来查看当前系统的路由表
2. 查看ARP缓存`arp -a`

## 文件
- 对于文件本身而言,可以通过文件描述符对文件进行操作,Linux本身并不会对文件进行上锁,所以当多个线程/进程通过同一个文件描述符对同一个文件write的时候会发生数据竞争,这是未定义行为
- 而对于vim而言,当打开一个文件,vim本身会临时创建一个文件,操作的都是这个临时的文件,同时vim本身会对文件进行一个保护,加flock给文件上锁(类似读写锁)
