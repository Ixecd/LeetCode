## 树

**二叉树**
- 含有n个节点的不同的二叉树的形态一共有 `1/(n + 1)C2n->n`
- 在n个节点构成的二叉树中,若叶节点的个数为n0,度为2的节点的个数为n2,则有: `n0 = n2 + 1`
- 使用数组存储二叉树 cur = i, cur->left = 2i+1, cur->right = 2i+2, 对于非完全二叉树,会造成很大的内存浪费.

**二叉树的非递归遍历**
- preOrder
```cpp
void preOrder(Node *root) {
    vector<int> res;
    stack<Node*> st, Node *p = root;
    while(1) {
        while (p) {
            res.push_back(p->val);  // 中
            st.push(p);
            p = p->left;            // 左
        }
        if (st.empty()) return;
        p = st.pop();
        p = p->right;               // 右
    }
}
```
- inOrder
```cpp
void inOrder(Node *root) {
    vector<int> res;
    stack<Node*> st, Node *p = root;
    while(1) {
        while (p) {
            st.push(p);
            p = p->left;            // 左
        }
        if (st.empty()) return;
        p = st.pop();
        res.push_back(p->val);      // 中
        p = p->right;               // 右
    }
}
```
- postOrder
```cpp
vector<int> postOrder(Node *root) {
    vector<int> res;
    stack<Node*> st;
    Node *p = root, *pre = nullptr;
    while (1) {
        while (p) {
            st.push(p);
            p = p->left;            // 左
        }
        if (st.empty()) return res;
        p = st.top();
        if (p->right != nullptr && p->right != pre) {
            p = p->right;           // 右
        } else {
            st.pop();
            res.push_back(p->val);  // 中
            pre = p;
            p = nullptr;
        }
    }
    return res;
}
```
- 创建二叉树(基于先序序列并且空指针用0表示)
```cpp
Node *buildTree() {
    int val;
    cin >> val;
    if (val == 0) return nullptr;
    Node *t = new Node(val);
    t->left = buildTree();
    t->right = buildTree();
    return t;
}
```
- 复制二叉树(基于后续遍历)
```cpp
Node *copyTree(Node *root) {
    if (root == nullptr) return nullptr;
    Node *newLeft = copyTree(root->left);
    Node *newRight = copyTree(root->right);
    Node *p = new Node(root->val);
    p->left = newLeft;
    p->right = newRight;
    return p;
}
```

- 如果一个非空二叉树的先根序列和中根序列相同,其所有非叶节点需满足只有`右子树`
- 由中跟序列和任意一种遍历序列都可以唯一地确定一颗二叉树

**森林**
- 使用 `左孩子-右兄弟二叉树表示法`结点结构为`struct Node { firstChild; Data; nextBrother; };`
- 常用框架(基于后序遍历)
```cpp
F(Node *t) {
    for (p = t->firstChild; p != nullptr; p = p->nextBrother)
        F(p); // 处理以p为根的子树
}
```
**Huffman**
- 压缩总编码长度
- 文件中出现频率高的字符的编码尽可能短
- 解码过程没有多义性,字符集中任何字符的编码都不是其他字符的编码的前缀
- Huffman算法:不断从所有节点中选出权值最小的那两个合并成一棵二叉树,新生成的节点作为father,其权值为俩子节点的权值之和,直到只剩下一颗二叉树为止.
- 霍夫曼树形态不唯一,编码不唯一,但最小编码长度唯一

1. 节点定义
```cpp
const int N = 1e3 + 10;
struct HuffmanNode {
    char data;
    int weight;
    HuffmanNode *left;
    HuffmanNode *right;
};
HuffmanNode *H[N];
```
2. 生成节点(不使用高级数据结构)
```cpp
void createHuffNode(char ch[], int freq[], int n) {
    for (int i = 0; i < n; ++i) {
        H[i] = new HuffmanNode;
        H[i]->data = ch[i];
        H[i]->weight = freq[i];
        H[i]->left = H[i]->right = nullptr;
    }
    sort(std::begin(H), std::begin(H) + n, [](HuffmanNode *left, HuffmanNode *right) {
        return left->weight < right->weight;
    });
}
```
3. 构建Huffman树(O(N^2))
```cpp
HuffmanNode *buildHuffmanTree(HuffmanNode *H[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        HuffmanNode *t = new HuffmanNode;
        t->data = ' ';
        t->weight = H[i]->weight + H[i + 1]->weight;
        t->left = H[i], t->right = H[i + 1];
        int j = i + 2;
        while (j < n && H[j]->weight < t->weight) {
            // 就算被覆盖也没有关系,因为Node在堆上并且前面已经串起来了
            H[j - 1] = H[j];
        }
        H[j - 1] = t;
    }
    return H[n - 1];
}
```
使用优先队列(O(Nlog(N)))
```cpp
HuffmanNode *buildHuffmanTree(std::priority_queue<HuffmanNode*> &pq) {
    while (!pq.empty()) {
        if (pq.size() == 1) return pq.front();
        HuffmanNode *left = pq.front(), pq.pop();
        HuffmanNode *right = pq.front(), pq.pop();
        HuffmanNode *t = new HuffmanNode;
        t->data = ' ';
        t->weight = left->weight + right->weight;
        t->left = left, t->right = right;
        pq.push(t);
    }
    return nullptr;
}
```
- 将霍夫曼树上每个非叶节点,左分支标记为0,右分支标记为1,从根到叶节点的路径所组成的字符的编码即为哈夫曼编码
- 解码: 保存霍夫曼编码表/JPEG:进保存编码长度,解码方通过编码长度即可复原编码表

**表达式树**
- 可以方便得到中(中根序列)/后(后根序列)缀表达式
- 可以表示整个代码解构,更有利于编译器对整个代码进行分析和优化

构造方法
1. 对于操作数,生成数节点,push到栈中
2. 对于操作符,生成符节点,从栈中弹出两个,分作作为当前符节点的右,左孩子,将符节点push到栈中
3. 最后栈中只剩下一个节点,即为根节点

**并查集**

经常需要的两种操作
1. 查询某个元素所属的集合
2. 合并两个集合
- 并查集的一种高效实现方式是使用树表示集合,只需要树的向上访问能力,只需要存储父节点信息
- 使用Father数组表示集合 Father[i]:节点i的父节点下标
```cpp
void make_set(int x) {
    // 单节点
    Father[x] = 0;
}
// O(N)
int find(int x) {
    // 永远都不会返回0
    if (Father[x] == 0) return x;
    return find(Father[x]);
}
// O(N)
void union(int x, int y) {
    // x的父亲指向y的父亲
    Father[find(y)] = find(x);
}
```
- find和union操作时间复杂度取决于树的高度

对并查集的优化(每个操作均摊时间复杂度近似为O(1))
1. 路径压缩
- 在find(x)操作中,找到元素x所在树的根fx之后,将x到根fx路径上所有节点的父亲都改为fx
```cpp
int find(x) {
    if (Father[x] <= 0) return x;
    Father[x] = find(Father[x]);
    return Father[x];
}
```
2. 按秩合并
- 每个节点维护一个秩,表示以该节点为根的子树的高度的上界
- Father[x] > 0:表示x父节点的地址
- Father[x] <= 0:表示x是根,Father[x]值为x秩的相反数
- 合并操作:具有较小秩的根指向具有较大秩的根
```cpp
void union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (Father[fx] < Father[fy]) // fy的秩小,存放的是相反数
        Father[fy] = fx;         // fx的秩大,加入fy不会改变原来的秩
    else {
        Father[fx] = fy;
        if (Father[fx] == Father[fy]) 
            Father[fy]--;       // fy的秩大,如果两个秩一样大,fy再大一个
    }
}
```