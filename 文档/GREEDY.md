## 贪心算法
**本质**
- 在问题的每个决策阶段,都选择当前看起来最优的选择,贪心地做出局部最优地策略,以获得全局最优解

**贪心和动态规划**
- 动态规划会根据之前阶段的所有决策来考虑当前决策,并使用过去子问题的解来构建当前子问题的解
- 贪心算法不会考虑过去的决策,而是一路向前地进行贪心选择,不断缩小问题范围,直至问题被解决

**零钱兑换**
- Q. 给定n个硬币,第i中硬币的面值为coins[i - 1],目标金额为amt,每种硬币可以重复选取,问能够凑出目标金额的最少硬币数量.如果无法凑出目标金额,返回-1
- E. coins : [1, 2, 5], target : 11, res : 3
- A. 给定目标金额,我们贪心地选择不大于且最接近它的硬币,不断循环该步骤,直至凑出目标金额为止
- H. 只对于特定序列的coins有效,比如[1, 20, 50], target = 60,贪心会得到11, 而动态规划会得到3
    ```cpp
    int charge(vector<int> const& coins, int target) {
        // 先对coins排序
        qsort(0, coins.size() - 1);
        int i = coins.size() - 1;
        int count = 0;
        while (target > 0) {
            while (i > 0 && coins[i] > target) --i;
            target -= coins[i];
            count++;
        }
        return target == 0 ? count : -1;
    }
    // 下面是快排
    int partition(vector<int> &ary, int low, int high) {
        int pivot = ary[low];
        while (low < high) {
            while (low < high && ary[high] >= pivot) --high;
            ary[low] = ary[high];
            while (low < high && ary[low <= pivot]) ++low;
            ary[high] = ary[low];
        }
        ary[low] = pivot;
        return low;
    }
    void qsort(vector<int> &ary, int low, int high) {
        if (low < high) {
            int pivot = partition(ary, low, high);
            qsort(ary, low, pivot - 1);
            qsort(ary, pivot + 1, high);
        }
    }
    ```
**贪心算法的优点与局限性**
- 贪心算法不仅操作直接/实现简单,而且通常效率也很高
- 但是对于零钱兑换问题,贪心算法无法保证找到全局最优解,并且有可能找到非常差的解,其更适合使用动态规划解决

**适用情况**
1. 可以保证找到最优解
2. 可以找到近似最优解

**贪心算法特性**
- 贪心算法的使用条件更加苛刻,其主要关注问题的两个特性
- 贪心选择性质
- 最优子结构
- 实际上对于许多问题,证明贪心算法的正确性并非易事,比如**满足什么条件的硬币组合可以使用贪心算法求解**,往往只能凭借直觉/举例子,来给出一个模棱两可的答案,而难以给出严谨的数学证明

有一篇论文给出了一个 $O(n^3)$ 时间复杂度的算法,用于判断一个硬币组合能否使用贪心算法找出任意金额的最优解

Pearson, D. A polynomial-time algorithm for the change-making problem[J]. Operations Research Letters, 2005, 33(3): 231-234

## 贪心算法解题步骤
1. 分析问题
2. 确定贪心策略
3. 正确性证明,通常使用反证法或数学归纳法

## 贪心算法典型例题
- 硬币找零问题: 在某些特定硬币组合下,贪心算法总能得到最优解
- 区间调度问题: 有一些任务,每个任务在一段时间内进行,目标是完成尽可能多的任务
- 分数背包问题: 给定物品和背包,如果每次选择性价比最高的物品,那么贪心算法在一定情况下可以得到最优解
- 股票买卖问题: 目标获取最大利润
- 霍夫曼编码问题: 每次选队列中权值最小的那两个建树
- Dijstra算法: 解决给定源点到其余各个顶点的最短路径的贪心算法

**最大容量问题**
- Q. 输入一个数组 ht ,其中的每个元素代表一个垂直隔板的高度.数组中的任意两个隔板,以及它们之间的空间可以组成一个容器.容器的容量等于高度和宽度的乘积(面积),其中高度由较短的隔板决定,宽度是两个隔板的数组索引之差.请在数组中选择两个隔板,使得组成的容器的容量最大,返回最大容量.
- A. 双指针,一个指向头,一个指向尾,计算容量,指向小的那个往里面移动,循环跳出条件是两个指针相遇
    ```cpp
    int getMaxCap(vector<int> const& ht) {
        int left = 0, right = ht.size() - 1;
        int cap = 0;
        while (left < right) {
            cap = max(cap, (right - left) * max(ht[left], ht[right]));
            if (ht[left] > ht[right]) right--;
            else ++left;
        }
        return cap;
    }
    ```

**最大切分乘积问题**
- Q. 给定一个正整数 $n$ ,将其切分为至少两个正整数的和,求切分后所有整数的乘积最大是多少?
- A.
1. 贪心策略确定
    - 根据经验,两个整数的乘积往往比他们的加和更大,假设从 $n$ 中分出一个因子2,则他们的乘积为 $2(n - 2)$, 即 $2(n - 2)$ >= $n$ , 即 $n$ >= 4,所以当这个整数大于等于4时,都应该被切分
- 贪心策略一: 如果切分方案中包含 >= 4的因子,那么它就应该被继续切分,最终切分的方案只应出现1/2/3这三种因子,优先切3
- 贪心策略二:在切分方案中,最多只应该出现两个2,因为三个2总是可以替换为两个3,从而获得更大的乘积
```cpp
int maxProductCutting(int n) {
    // 当n <= 3时,必须切分出一个1, 单独判断而已
    if (n <= 3) return 1 * (n - 1);
    // 开始贪心
    int a = n / 3; // 6 -> 3 * 3
    int b = n % 3; // 7 -> 3 * 3 * 1 -> 3 * 2 * 2
                   // 8 -> 3 * 3 * 2
    if (b == 1) // 余数为1, 将一对 1 * 3 转换为 2 * 2
        return (int)pow(3, a - 1) * 2 * 2;
    if (b == 2) // 余数为2,不做处理
        return (int)pow(3, a) * 2;
    return (int)pow(3, a);
}
```
**快速幂**
- 本质:指数折半
```cpp
long long int q_pow(int a, int n) {
    long long int result = 1;
    while (n > 0) {
        if (n & 1) 
            result *= a;
        n >>= 1;
        a *= a;
    }
    return result;
}
```
