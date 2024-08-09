# 动态规划
## 初探动态规划
**本质**
- 将问题分解为一系列更小的子问题,并通过存储子问题的解来避免重复计算,从而大幅提升时间效率

**手段**
1. 暴力回溯+剪枝
2. 记忆化搜索
    - 所谓记忆化搜索是指将`所有重叠子问题都只被计算一次`
    - 当计算dp[i]时,将结果记录在mem[i]中
    - 之后再次遇到要计算dp[i],直接从mem[i]中获取即可
    - 下面以台阶问题举例
    ```cpp
    /* 记忆化搜索 */
    int dfs(int i, vector<int> &mem) {
        if (i == 1 || i == 2) return i;
        if (mem[i] != -1) return mem[i];
        // 这里也是很有讲究的
        // 先dfs(i - 1) 后 dfs(i - 2)
        // 这样所有重叠问题在dfs(i - 1)递归的时候都被记录了,在dfs(i - 2) 中会非常高效
        int count = dfs(i - 1, mem) + dfs(i - 2, mem);
        mem[i] = count;
        return count;
    }

    int climbingStairsDFSMem(int n) {
        vector<int> mem(n + 1, -1);
        return dfs(n, mem);
    }
    ```
3. 动态规划
    - 记忆化搜索时一种`从顶至底`的方法,从原问题开始递归地将较大子问题分解为较小子问题,直至已知的最小子问题结果,之后回溯,逐层收集子问题的解,构建出原问题的解
    - 相反,动态规划是一种`从底至顶`的方法,从最小子问题的解开始,迭代地构建更大子问题的解,直至得到原问题的解
    - 动态规划不包含回溯过程,只需使用循环迭代实现,无需使用递归,dp数组用来存储子问题的解,其同时也起到了记忆化搜索中mem相同的记录作用
    ```cpp
    int climbingStairsDP(int n) {
        if (n == 1 || n == 2) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) 
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
    ```
    - 与回溯算法一样,动态规划也使用`状态`概念来表示问题求解的特定阶段,每个状态都对应一个子问题以及相应的局部最优解
    - dp数组称为`dp表`,dp[i]表示状态i对应子问题的解
    - 将最小子问题对应的状态(第1阶梯和第2阶梯)称为`初始状态`
    - 递推公式`dp[i] = dp[i - 1] + dp[i - 2]`称为`状态转移方程`

4. 空间优化
- 由于上面求阶梯问题的地推公式dp[i]只与dp[i - 1]和dp[i - 2]有关,所以无需一个dp数组来存储所有子问题的解
    ```cpp
    int climb(int m) {
        if (n == 1 || n == 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
    ```
- 空间复杂度从$O(n)$ 降到 $O(1)$
- 这种空间优化技巧被称为`滚动变量`或`滚动数组`

## 动态规划问题特性
**分治/动态规划/回溯的区别**
- 分治算法递归地将原问题划分为多个相互独立地子问题,直至最小子问题,并在回溯中合并子问题地解,最终得到原问题的解
- 动态规划也对问题进行递归分解,但与分支算法的主要区别是,动态规划中的子问题是相互依赖的,在分解过程中会出现许多重复子问题
- 回溯算法在尝试和回退中穷举所有可能的解,并通过剪枝避免不必要的搜索分支,将原问题的解由一系列决策步骤构成
- 实际上,动态规划常用来求解最优化问题,他们不仅包含重叠子问题,还具有另外两大特性:最优子结构和无后效性

**最优子结构**
- 变种1.爬楼梯问题带有cost,第i个台阶对应cost[i]表示当在i台阶时,需要支付cost[i],之后可以选择跳1/2步
```cpp
int climb(int n, vector<int> const&cost) {
    if (n == 1 || n == 2) return cost[0];
    vector<int> dp(n + 1, 0);
    dp[1] = dp[2] = cost[0];
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
}
```
- 变种2.同样带有cost,但是跳到第i个台阶需要支付cost[i]
```cpp
int climb2(int n, vector<int> const& cost) {
    if (n == 1 || n == 2) return cost[n];
    vector<int> dp(n + 1, 0);
    dp[1] = cost[1];
    dp[2] = cost[2];
    for (int i = 3; i <= n; ++i) 
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    return dp[n];
}
```
- 由于dp[i] 只依赖于 dp[i - 1] 和 dp[i - 2] 并且 cost不会变化
- 可以使用滚动数组来进行优化
```cpp
int climb(int n, vector<int> const& cost) {
    if (n == 1 || n == 2) return cost[n];
    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; ++i) {
        int tmp = b;
        b = min(a, b) + cost[i];
        a = tmp;
    }
    return b;
}
```

**无后效性**
- 定义:给定一个确定的状态,它的未来发展只与当前状态有关,而与过去经历的所有状态无关.例如,对于爬楼梯问题,当给定状态i,其只会发展出状态i + 1和状态i + 2,对于做出这两中选择时,无需考虑状态i之前的状态,他们对i的未来没有影响
- 变种3:给定一个共有n阶的楼梯,你每步可以上1阶或者2阶,但不能连续两轮跳1阶,请问有多少种方案可以爬到楼顶?
    - 如果上一次是通过跳1阶上来的,那么下一次就必须跳2阶,这意味着**下一步选择不能由当前状态(当前所在楼梯阶数)独立决定,还和前一个状态有关**
    - 所以需要扩展定义,**状态[i,j]表示处在第i阶并且上一轮跳了j阶**,其中j = 1/2
```cpp
int climb(int n) {
    if (n == 1 || n == 2) return 1;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][1] = 1;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = min(dp[i - 2][1], dp[i - 2][2]);
    }
    return min(dp[n][1], dp[n][2]);
}
```

```cpp
int climb(int n) {
    if (n == 1 || n == 2) return 1;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    vector<bool> barr(n + 1, ture);
    // dp[i][j] -> j 当前阶梯 1 可用, 2 不可用
    dp[1][1] = 1;
    barr[2] = false;
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = min({dp[i - 1][1], dp[i - 2][1], });
    }
}
```
## 动态规划解题思路
**问题判断**
1. 先观察问题是否适合使用回溯解决,适合回溯解决的问题通常满足**决策树模型**,其中每个节点代表一个决策,每一条路径代表一个决策序列
2. 加分项
    1. 问题包含最大(小)或最多(少)等最优描述
    2. 问题的状态能够使用一个列表/多为矩阵/树来表示
3. 减分项
    1. 问题的目标是找出所有可能的解决方案,而不是最优解
    2. 问题描述中有明显的排列组合特性,需要返回具体的多个方案

**问题求解步骤**
1. 描述决策
2. 定义状态
3. 建立dp表
4. 推导状态转移方程
5. 确定边界条件

Q: 给定一个$n × m$的二维网格grid,网格中的每个单元格包含一个非负整数,表示该单元格的代价.机器人以左上角单元格为起始点,每次只能向下或者向右移动一步,直至到达右下角单元格.请返回从左上角到右下角的最小路径和.


```cpp
void Solution(vector<vector<int>> const &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = grid[0][0];
    for (int i = 2; i <= n; ++i) 
        dp[i][1] += dp[i - 1][1] + grid[i - 1][0];
    for (int j = 2; j <= m; ++j) 
        dp[1][j] += dp[1][j - 1] + grid[0][j - 1];

    for (int i = 2; i <= n; ++i) 
        for (int j = 2; j <= m; ++j) 
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
    cout << dp[n][m] << endl;
}
```

## 0-1背包问题
- 给定$n$个物品,第i个物品的重量为weight[i - 1],价值为value[i - 1],和一个容量为cap的背包,每个物品只能选择一次,求在限定背包容量下能放入物品的最大价值
- 可以将0-1背包问题看作一个由$n$轮决策组成的过程,对于每个物品都有不放入和放入两种决策,所以满足决策树模型
1. 思考每轮的决策,定义状态,得到dp表
    - 首先肯定是二维dp[i][j] 物品编号i和背包容量j
2. 找出最优子结构,进而导出状态转移方程
    当我们做出物品i的决策后,剩余的是i-1个物品决策的子问题,可分为以下两种情况
    1. 不放入物品i dp[i][j] = dp[i - 1][j]
    2. 放入物品i   dp[i][j] = dp[i - 1][j - weight[i]] + value[i]
3. 确定边界条件和状态转移顺序
    - 当无物品或背包容量为0时,最大价值为0,即首列和首行都为0
    - 通过两层for循环即可
    - 因为是0-1背包,所以外层遍历物品,内层遍历背包

```cpp
void Zero_One(vector<int> &weight, vector<int> &value, int cap) {
    int n = weight.size() + 1;
    vector<vector<int>> dp(n, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= cap; ++j) 
            if (weight[i - 1] > j) // 不选
                dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
    }
    return dp[n][cap];
}
```
4. 空间优化
- 由于每个状态都只和其上一行的状态有关,所以可以使用两个滚动数组前进,将空间复杂度从$O(n^2)$降至$O(n)$
```cpp
void Zero_One(vector<int> &weight, vector<int> &value, int cap) {
    vector<int> dp(cap + 1, 0);
    int n = weight.size();
    for (int i = 0; i < n; ++i) {
        for (int j = cap; j >= weight[i]; --j) {
                dp[j] = max(dp[j - weight[i]] + value[i], dp[j]);
        }
    }
    return dp[cap];
}
```

## 完全背包
- 和0-1的区别在于这个物品可以无限次取用,求最大价值
- 在0-1背包问题中,每个物品只有一个,因此将物品i放入背包后,只能从前i - 1个物品中选择
- 在完全背包问题中,每个物品是无限个,因此将物品i放入背包后,仍然可以从前i个物品中选择
    1. 不放入物品i dp[i, c] = dp[i - 1, c]
    2. 放入物品i dp[i, c] = dp[i, c - weight[i]] + value[i], dp[i]
    ```cpp
    int unboundedKnapsackDPComp(vector<int> &wgt, vector<int> &val, int cap) {
        int n = wgt.size();
        vector<int> dp(cap + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int c = 1; c <= cap; ++c) 
                if (wgt[i - 1] > c) continue;
                else dp[c] = max(dp[c], dp[c - wgt[i - 1] + val[i - 1]]);
        }
        return dp[cap];
    }
    ```

**零钱兑换(Tencent CDG-金融科技一面)**
- Q. 给定n个硬币,第i中硬币的面值为coins[i - 1],目标金额为amt,每种硬币可以重复选取,问能够凑出目标金额的最少硬币数量.如果无法凑出目标金额,返回-1
- E. coins : [1, 2, 5], target : 11, res : 3
1. 思考每轮的决策,定义状态,从而得到dp表
    - [i, a]对应的子问题为:**前i种硬币能够凑出金额a的最少硬币数量**,记为dp[i, a]
2. 找出最优子结构,进而推导出状态转移方程
    - 本体求最小值,因此将运算符max()更改为min()
    - 优化主体是硬币数量而非商品价值,因此在选中硬币时执行+1即可
3. 确定边界条件和状态转移顺序
    - 当金额为0时,凑出它的最少硬币数量为0,dp[i, 0] 都为0
    - 当无硬币时,,为了使得状态转方程中的min能够识别并过滤掉无效解,使用0x3f3f3f3f来表示无穷大,dp[0, c] = 0x3f3f3f3f
    ```cpp
    int charge(vector<int> const& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int j = 0; j <= target; ++j) 
            dp[0][j] = 0x3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            for (int c = 1; c <= target; ++c) {
                if (c - coins[i - 1] >= 0) 
                    dp[i][c] = min(dp[i - 1][c], dp[i][c - coins[i - 1]] + 1);
            }
        }
        return dp[n][target];
    }
    ```
4. 空间优化(一般侧重点都在背包大小上, 此时很容易遗漏dp数组初始化)
    ```cpp
    int charge(vector<int> const& coins, int target) {
        int n = coins.size();
        vector<int> dp(target + 1, 0x3f3f3f3f);
        dp[0] = 0; // 重要
        for (int i = 1; i <= n; ++i) 
            for (int c = 1; c <= target; ++c) {
                if (c - coins[i - 1] >= 0) 
                    dp[c] = min(dp[c], dp[c - coins[i - 1]] + 1);
            }
        return dp[target] == 0x3f3f3f3f ? -1 : dp[target];
    }
    ```
**零钱兑换II**
- Q. 给定$n$种硬币,第i种硬币的面值为coins[i - 1],目标金额为target,每种硬币可以重复选取,求凑出目标金额硬币组合的数量
    ```cpp
    int charge2(vector<int> const& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // 初始化dp
        for (int i = 0; i <= n; ++i) 
            dp[i][0] = 1; // 注意:当金额为0时,组合数量为1
        for (int j = 0; j <= target; ++j) 
            dp[0][j] = 0; // 当硬币数量为0时,组合数量为0

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j - coins[i - 1] >= 0) 
                    // 不选和选i这两种方案之和
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
    ```
- 空间优化
    ```cpp
    int charge2(vector<int> const& coins, int target) {
        int n = coins.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j - coins[i - 1] >= 0) 
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                else dp[j] = dp[j];
            }
        }
        return dp[target];
    }
    ```
**完全背包总结**
- 两层for循环,外层遍历物品,内层遍历背包,都是从左往右遍历,为了方便理解,dp数组的大小都扩大1
- 递归公式为 (前者表示不选,后者表示选,i->物品,j->背包)
    1. dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1); 最少方案
    2. dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];         所有方案
    3. dp[i][j] = max(dp[i - 1][j], dp[i][j - coins[i - 1]] + value[coins[i - 1]]) 最大价值
- 要注意dp数组的初始化(和上面一一对应)
    1. dp[i][0] = 0, dp[0][j] = 0x3f3f3f3f
    2. dp[i][0] = 1, dp[0][j] = 0;
    3. dp[i][0] = 0, dp[0][j] = 0

## 编辑距离
- Levenshtein距离,指两个字符串之间互相转换的最少修改次数,通常用于在信息检索和自然语言处理种度量两个序列的相似度
- Q:输入两个字符串 $s$ 和 $t$ ,返回将 $s$ 转换为 $t$ 所需的最少编辑步数,三种操作,增删改
    ```cpp
    int LSA(string const& s, string const& t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // 注意初始化dp
        for (int i = 0; i <= n; ++i) 
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
        return dp[n][m];
    }
    ```