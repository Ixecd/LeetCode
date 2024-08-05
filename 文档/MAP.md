## 图

**定义**
- 图G由两个集合V和E组成,记为G=(V,E);其中V是顶点的有穷集合,E个连接V中两个不同顶点的边的有穷集合
- 若图中边限定为从一个顶点指向另一个顶点,则称此图为有向图,若边无方向,则称为无向图
- 如果一个图中重复多次出现一条边,通常是带权重的情况下,称为多重图

**度**
- 若图G是无向图, v包含于V(G), E(G)中以v为端点的边的个数,称为v的度
- 若图G是有向图, v的出度是以v为始点的边的个数,v的入度是以v为终点的边的个数,顶点的度 = 入度 + 出度
- 顶点的度数之和就是边数的两倍

**路径**
- 若图存在一条路径可以从vp到vq,则称为vp到vq的一条路径,路径的长度是该路径上边的个数
- 如果一条路径上除了起点和终点可以相同外,再不能有相同的顶点,则称此路径为简单路径
- 如果一条路径上起点和终点相同,并且路径长度大于等于2,则称为简单回路
- 欧拉回路(一笔画,每条边经过一次), 汉密尔顿回路(每个顶点经过一次)

**子图**
- 设G,H是图,如果V(H)包含于V(G), E(H)包含于E(G),则称H是G的子图,G是H的母图
- 若H是G的子图,并且V(H) = V(G),则称H为G的支撑子图

**连通图**
- 设G是图,若存在一条从顶点vi到顶点vj的路径,则称vi与vj可及(连通)
- 若G为无向图,并且V(G)中任意两顶点都可及,则称G为连通图
- 若G为有向图,并且V(G)中任意两个不同的顶点vi和vj,vi与vj可及,vj与vi也可及,则称G为强连通图
- 设图G = (V, E)是无向图,若G的子图Gk是一个连通图,则称Gk为G的连通子图;G的极大连通子图称为G的连通分量
- 设图G = (V, E)是有向图,若G的子图Gk是一个强连通图,则称Gk为G的强连通子图;G的极大强连通子图称为G的强连通分量
- 一个图的连通子图不一定唯一
- 一个图的连通分量也不一定唯一
- 一个图的强连通子图也不一定唯一
- 一个图的强连通分量也不一定唯一

## 图的存储结构

**邻接矩阵**
- 用顺序方式存储图的顶点表v0,v1,...vn-1,图的边用nxn阶矩阵A=(aij)表示
1. 非权图
- a[i][i] = 0,
- a[i][j] = 1, 当i != j 且 vi与vj之间存在边
- a[i][j] = 0, 当i != j 且 vi与vj之间不存在边
2. 权图
- a[i][i] = 0,
- a[i][j] = weight, 当i != j 且vi与vj之间存在边
- a[i][j] = ∞, 当i != j 且vi与vj之间不存在边

*特点*
- 无向图的邻接矩阵是对称矩阵,有向图邻接矩阵不一定对称
- 借助邻接矩阵可以方便求出图中顶点的度, 矩阵的第i行(或第i列)的1的个数就是顶点vi的度

**邻接表**
- 顺序存储顶点表
- 对图中的每个顶点建立一个单链表,第i个单链表中的节点包含顶点vi的所有邻接顶点(边链表)
- 与顶点v邻接的所有顶点以某种次序组成的单链表称为顶点v的边链表
- 有向图中一个边节点对应一条边, 无向图中两个边节点对应一条边

*结构*
```cpp
struct Vertex {     // 顶点表中节点结构
    int verName;    // 顶点名称
    Edge *adjacent; // 边链表的头指针
};

struct Edge {       // 边节点的结构
    int verAdj;     // 邻接顶点序号
    int cost;       // 边的权值
    Edge *next;     // 指向下一个边节点的指针
};
```
- 对于使用邻接表存储的有向图其计算节点的度时间复杂度为O(ne),如何降低时间复杂度

**有向图的逆邻接表**
- 再有向图的逆邻接表中,第i个边链表连接的边都是指向顶点i的边
- 通过构建逆邻接表很容易统计出图中每个节点的入度

## 图的遍历
- 为了避免重复访问,可以使用一个辅助数组vis[]来记录已经访问过的节点

**DFS**
```cpp
void DFS(Vertex* head, int v, int vis[]) {
    std::cout << v << ' ';
    vis[v] = 1;
    Edge *p = head[v].adjacent;
    while (p) {
        if (vis[p->verAdj] == 0) 
            DFS(head, p->verAdj, vis);
        p = p->next;
    }
}
```
更简单的写法
```cpp
void DFS(Vertex* head, int v, int vis[]) {
    std::cout << v << ' ';
    vis[v] = 1;
    for (Edge *p = head[v].adjacent; p != nullptr; p = p->next) 
        if (vis[p->verAdj] == 0) 
            DFS(head, p->verAdj, vis);
}
```
*注意*
- 一次DFS只能遍历一个连通分量
- 非连通图需要多次调用DFS算法
```cc
for (int i = 0; i < n; ++i) 
    if (vis[i] == 0)
        DFS(head, i, vis);
```
**BFS**
- 类似于树的层次遍历,使用一个队列,记忆还没有被处理的顶点
- 同样也需要一个vis来标识一个节点是否被访问过
```cpp
void BFS(Vertex *head, int v, int n, int vis[]) {
    std::queue<int> que;
    for (int i = 0; i < n; ++i) vis[i] = 0;
    std::cout << v << ' ';
    vis[v] = 1;
    que.push(v);
    while (!que.empty()) {
        v = que.front(); que.pop();
        for (Edge *p = head[v].adjacent; p != nullptr; p = p->next) {
            if (vis[p->verAdj] == 0) {
                std::cout << p->verAdj << ' ';
                vis[p->verAdj] = 1;
                que.push(p->verAdj);
            }
        }
    }
}
```
**判断无向图中是否有环**
1. DFS, 遍历过程中遇到之前访问过的顶点即有环
2. 并查集, 每次读入一条边(x,y),如果x和y之前都被union过了,那么这次find俩必然相等
```cc
if (find(x) == find(y)) return true;
else union(x, y)
```
**判断有向图中是否有环**
1. DFS, 遍历过程中遇到之前访问过的顶点说明有环
2. 并查集, 但是不能用秩,要保证x是y的father
```cpp
bool HasCricle(Vertex* head, int v, int vis[]) {
    vis[v] = 1;
    for (Edge *p = head[v].adjacent; p != nullptr; p = p->next) {
        int k = p->verAdj;
        if (vis[k] == 0) 
            if (HasCricle(head, k, vis)) return true;
        if (vid[k] == 1) return true;
    }
    vis[v] = 2;
    return false;
}
```

## 拓扑排序
- 一个任务可以被分解为若干个子任务,要完成整个任务就可以转化为完成所有的子任务
- 某些情况下,各子任务之间有序,要求一些子任务必须先于另外一些子任务被完成
- 个任务之间的先后关系可以用有向图来表示

AOV网(Activity On Vertex Network)
- 在有向图中,顶点表示活动(任务),有向边表示活动(任务)之间的先后关系,这样的有向图为AOV网
- 在AOV网络中,如果活动Vi必须在活动Vj之前进行,则存在有向边Vi->Vj
- AOV网络中,不能出现有向回路

**拓扑序列**
- 把AOV网中所有顶点排成一个线性序列,若AOV网中存在有向边Vi->Vj,则在该序列中,Vi必须在Vj之前
- 在拓扑序列中,先进行的任务一定在后进行的任务的前面,按照拓扑序列完成各子任务,就可以顺利完成整个任务
- 构造AOV网的拓扑序列的过程被称为拓扑排序

**拓扑排序算法基本步骤**
1. 从图中选择一个入度为0的顶点并输出
2. 从图中删除该顶点以及该顶点引出的所有边
3. 执行1/2直至所有顶点已输出,或图中剩余顶点入度均不为0(说明有环,无法继续拓扑排序)
- 对于任何无环的AOV网,其顶点均可排成拓扑序列,其拓扑序列未必唯一

**实现**
1. 计算入度
```cpp
// 邻接表
bool InDegree(Vertex Head[], int n, int count[]) {
    for (int i = 0; i < n; ++i) count[i] = 0;
    for (int i = 0; i < n; ++i) {
        for (Edge *p = Head[i].adjacent; p != nullptr; p = p->next) {
            int k = p->verAdj;
            count[k]++;
        }
    }
}
// 邻接矩阵(有向)
bool InDegree(vector<vector<int>> &Vertex, int count[]) {
    int n = Vertex.size();
    for (int i = 0; i < n; ++i) coutn[i] = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            if (Vertex[i][j] != 0) count[j]++;
}
```
2. 得到拓扑序列
```cpp
bool ToDoOrder(Vetex Head[], int n) {
    // 最简单写法用数组实现栈
    vector<int> sequence;
    int count[N]; int stack[N], top = -1;
    InDegree(Head, n, count);
    for (int i = 0; i < n; ++i) 
        if (count[i] == 0) stack[++top] = i;
    for (int i = 0; i < n; ++i) {
        if (top == -1) return false; // 有环
        int j = stack[top--];
        sequence.push_back(j);
        for (Edge *p = Head[j].adjacent; p != nullptr; p = p->next) {
            int k = p->verAdj; count[k]--;
            if (count[k] == 0) stack[++top] = k;
        }
    }
    return true;
}
```
3. 优化
- 用count数组空闲的空间组织栈
- top指向第一个入度为0的顶点序号,count[top]是第二个入度为0的顶点序号,最后一个入度为0顶点所对应的count数组中的元素值为-1,表示栈底
```cpp
bool TopuOrder(Vetex Head[], int n) {
    vector<int> sequence;
    int count[N]; int top = -1;
    InDegree(Head, n, count);
    for (int i = 0; i < n; ++i) 
        if (count[i] == 0) {
            count[i] = top;
            top = i;
        }
    for (int i = 0; i < n; ++i) {
        if (top == -1) return false; // 有环
        int j = top;
        top = count[top];
        sequence.push_back(j);
        for (Edge *p = Head[j].adjacent; p != nullptr; p = p->next) {
            int k = p->verAdj; count[k]--; // 随便减,不影响栈,只有当入度为0的时候才会加到栈中
            if (count[k] == 0) {
                count[k] = top;
                top = k;
            }
        }
    }
    return true;
}
```
4. 拓展
- 可以使用DFS得到逆拓扑序
```cpp
vector<int> reSequence;
void DFS_TopuSort(Vertex *Head, int v, int vis[]) {
    vis[v] = 1;
    for (Edge *p = Head[v].adjacent; p != nullptr; p = p->next) 
        if (vis[p->verAdj] == 0) DFS_TopuSort(Head, p->verAdj, vis);
    reSequence.push_back(v);
}
// 初始调用
for (int i = 0; i < n; ++i) 
    if (vis[i] == 0) 
        DFS_TopuSort(Head, i, vis);
```

## 关键路径
- AOV网(Activity On Vertex):顶点表示活动(任务),有向边表示活动(任务)间的先后关系
- AOE网(Activity On Edges):有向边表示活动(任务),用边上的权值表示任务的持续事件,顶点称为事件(Event):表示其入边的任务已完成,出边的任务可开始的状态
- 在AOE网中,有些活动可以并行进行,但有些活动必须顺序进行
- 从源点到各个顶点,以致从源点到汇点的路径可能不止一条,这些路径的长度也可能不同
- 只有各条路径上所有活动都完成了,整个工程才算完成
- 完成整个工程所需的最短事件取决于从源点到汇点的最长路径长度,这条路径长度最长的路径就叫做关键路径
- 路径长度:路径上的各边权值之和

**与关键活动有关的量**
1. 事件vj的最早发生时间ve(j)
2. 事件vj的最迟发生时间vl(j)
3. 活动ai的最早开始时间e(i)
4. 活动ai的最迟发生时间l(i)
- 关键路径:从源点到汇点的最长路径
- 关键活动:关键路径上的活动,活动的最早开始时间等于活动的最迟开始时间,即e(i) = l(i)

**求关键活动的步骤**
1. 对AOE网进行拓扑排序,按顶点拓扑序求各顶点vj的最早发生时间ve(j)
2. 按顶点的逆拓扑序求各顶点vj的最迟发生时间vl(j)
3. 根据各顶点ve和vl值,求出各活动ai的最早开始时间e(i)和最迟开始时间l(i),若e(i)等于l(i),则ai为关键活动
```cpp
// 计算顶点的最早发生时间 ve(j),假定途中顶点已按拓扑序编号
void VertexEarliestTime(Vertex Head[], int Topo[], int n, int ve[]) {
    for (int i = 0; i < n; ++i) 
        ve[i] = 0;
    for (int i = 0; i < n; ++i) 
        for (Edge *p = Head[Topo[i]].adjacent; p != nullptr; p = p->next) {
            int k = p->verAdj;
            if (ve[Topo[i]] + p->cost > ve[k]) 
                ve[k] = ve[Topo[i]] + p->cost;
        }
}
// 或者直接在TopuOrder的时候计算ve(j)
bool ToDoOrder(Vetex Head[], int n) {
    vector<int> sequence;
    int count[N]; int stack[N], top = -1;
    InDegree(Head, n, count);
    for (int i = 0; i < n; ++i) 
        if (count[i] == 0) stack[++top] = i;
    for (int i = 0; i < n; ++i) {
        if (top == -1) return false; // 有环
        int j = stack[top--];
        sequence.push_back(j);
        for (Edge *p = Head[j].adjacent; p != nullptr; p = p->next) {
            int k = p->verAdj; count[k]--;
            if (count[k] == 0) stack[++top] = k;
            if (ve[k] + p->cost > ve[k]) ve[k] = ve[k] + p->cost;
        }
    }
    return true;
}
// 计算顶点的最迟发生时间
void VertexLatestTime(Vertex *Head, int n, int Topo[], int ve[], int vl[]) {
    for (int i = 0; i < n; ++i) 
        vl[i] = ve[n - 1];
    for (int i = n - 1; i >= 0; --i) 
        for (Edge *p = Head[Topo[i]].adjacent; p; p = p->next) {
            int k = p->verAdj;
            if (vl[k] - p->cost < vl[Topo[i]]) 
                vl[Topo[i]] = vl[k] - p->cost;
        }
}
// 求各活动的最早开始时间和最迟开始时间,求关键活动
void ActivityStartTime(Vertex *Head, int n, int ve[], int vl[]) {
    for (int i = 0; i < n; ++i) 
        for (Edge *p = Head[i].adjacent; p; p = p->next) {
            int k = p->verAdj;
            int e = ve[i];
            int l = vl[k] - p->cost;
            if (e == l) // 输出关键活动
                std::cout << i << "->" << j << std::endl;
        }
}
```
## 图的最短路径

**无权图最短路径**
- BFS过程中,当访问某个顶点的时候,就确定了该点与源点的最短路径
```cpp
// dist[i]:从源点到顶点i的最短路径,初值-1
// path[i]:从源点到顶点i的最短路径上,顶点i的前驱顶点,初值-1
void BFS(Vertex *Head, int n, int s, int dist[], int path[]) {
    std::queue<int> que;
    for (int i = 0; i < n; ++i) {
        path[i] = -1;
        dist[i] = -1;
    }
    dist[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.pop();
        for (Edge *p = Head[v].adjacent; p; p = p->next) {
            int w = p->verAdj;
            if (dist[w] == -1) {
                dist[w] = v +1
                path[w] = v;
                que.push(w);
            }
        }
    }
}
```
**Dijkstra算法**
- 为了解决带权图的中,长度更长的反而更小
- Cpp中表示+∞的方法
    1. INT_MAX: 1 << 31 - 1, 需要 limits.h, 且对于int类型加法,乘法会溢出,不推荐
    2. 0x3f3f3f3f: 1061109567, 10多亿,一般不会溢出,推荐使用
```cpp
// dist[i]: 从源点s到顶点i的最短距离,初始时dist[s] = 0, dist[i] = ∞
// path[i]: s到i最短路径上i的前驱顶点编号,初始时path[i] = -1
// S[i]: 顶点i是否在集合S中
const int INF = 0x3f3f3f3f, N = 1e5 + 10;
void Dijkstra(Vertex *Head, int n, int s, int dist[], int path[]) {
    int S[N], i, j, min, v, w;
    for (int i = 0; i < n; ++i) 
        path[i] = -1, dist[i] = INF, S[i] = 0;
    dist[s] = 0;
    for (i = 0; i < n; ++i) {
        min = INF;
        // 从不在S集合中的顶点中选D值最小的顶点v,第一次的话就会找到s
        for (j = 0; j < n; ++j) 
            if (S[j] == 0 && dist[j] < min) {
                min = dist[j];
                v = j;
            }
            // 把v放入S
            S[v] = 1;
            for (Edge *p = Head[v].adjacent; p; p = p->next) {
                w = p->verAdj;
                // 更新v的邻接顶点的值
                if (S[w] == 0 && dist[v] + p->cost < dist[w]) {
                    dist[w] = dist[v] + p->cost;
                    path[w] = v;
                }
            }
    }
}
```
- 打印路径
```cpp
void PrintPath(int start, int end) {
    if (start == end) {
        std::cout << start << ' ';
        return;
    }
    PrintPath(s, path[end]);
    std::cout << end << ' ';
}
```

**Floyd算法**
- G是带权图,对每一对顶点vi!=vj,求vi与vj之间的最短路径
    1. 若权值为正,可依此把每个顶点作为源点,执行Dijkstra算法
    2. Floyd算法(使用邻接矩阵存储图)
```cpp
// D[i][j]:从顶点i到顶点j的最短距离,初值等于邻接矩阵
// path[i][j]:i到j最短路径上i的下一个顶点编号
// A[][]:邻接矩阵
void Floyd(int A[N][N], int n, int D[N][N], int path[N][N]) {
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            D[i][j] = A[i][j];
            if (i != j && A[i][j] < 0x3f3f3f3f) path[i][j] = j;
            else path[i][j] = -1;
        }
    // 三层for大法
    for (int k = 0; k < n; ++k) 
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[i][k];
                }
}
```
- 打印路径
```cpp
void PrintPath(int start, int end) {
    std::cout << start << ' ';
    int k = start;
    while (k != end) {
        std::cout << path[k][end];
        k = path[k][end];
    }
}
```

## 图的最小支撑树及图应用
*最小支撑树*
- 无向带权连通图G,其顶点个数为n,由G中n个顶点和n-1条边构成的连通子图,称为G的一颗支撑树,亦称生成树
- 边权之和最小的支撑树称为G的最小支撑树
- 应用场景:在n个地点之间建立造价最低的网路

**Prim算法(O(N^2))**
- 假设图使用邻接矩阵存储,结果存储在数组TE中
- TE[]是最小支撑树的边集合,每个数组元素TE[i]表示一条边,TE[i]由head/tail/cost三个域构成,分别存放在边的两个端点和权值
```cpp
struct Edge {
    int head, tail;
    int cost;
};
Edge TE[1000];
```
- 算法实现
```cpp
int Prim(int A[N][N], int n, Edge TE[]) { // 以0为起点构造MST
    int Lowcost[N], U[N], ans = 0;
    for (int i = 0; i < n; ++i) {
        Lowcost[i] = A[0][i];
        U[i] = 0;
    }
    U[0] = -1; // 以0为起点构造MST
    for (int i = 0; i < n - 1; ++i) { // 找n-1条边,循环n-1次
        int v = 0, min = INF;
        for (int j = 0; j < n; ++j) {
            if (U[j] != -1 && Lowcost[j] < min) {
                v = j;
                min = Lowcost[j];
            }
        }
        if (v == 0) return 0x3f3f3f3f; // 不存在跨边,不连通
        TE[i].head = U[v];
        TE[i].tail = v;
        TE[i].cost = Lowcost[v];
        ans += Lowcost[v];
        U[v] = -1;
        // 更新v在V-U中的邻接顶点的Lowcost和U值
        for (int j = 0; j < n; ++j) {
            if (U[j] != -1 && A[v][j] < Lowcost[j]) {
                Lowcost[j] = A[v][j];
                U[j] = v;
            }
        }
    }
    return ans;
}
```
**Kruskal算法(O(eLge))**
- 借助并查集,每个连通分量看作一个集合,顶点看作集合元素
```cpp
int  Kruskal(Edge E[], int n, int e, Edge TE[]) {
    for (int i = 0; i < n ++i) Make_set(i);
    sort(E, e); // 按权值递增排序,时间复杂度为O(eloge)
    int ans = 0, k = 0; // k是MST中边的计数器
    for (int i = 0; i < e; ++i) {
        if (k == n - 1) return ans;
        int u = E[i].head, v = E[i].tail, w = E[i].cost;
        if (Find(u) != Find(v)) {
            TE[k].head = u, TE[k].tail = v, TE[k].cost = w;
            ++k;
            ans += w;
            Union(u, v);
        }
    }
    return INF;
}
```