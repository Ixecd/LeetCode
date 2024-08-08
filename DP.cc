#include <bits/stdc++.h>
using namespace std;

// 台阶问题(给一个共有n阶的楼梯,每步可以走1/2步,求解决方法)
vector<int> choice{1, 2};
int res = 0;

void backtricking(vector<int> &choice, int cur, int n, int &res) {
    if (cur == n) {
        res++;
    }

    for (int i = 0; i < choice.size(); ++i) {
        if (cur + choice[i] > n)
            continue;
        backtricking(choice, cur + choice[i], n, res);
    }
}

int climb(int n, vector<int> const& cost) {
    if (n == 1 || n == 2) return cost[0];
    vector<int> dp(n + 1, 0);
    for (int i = 3; i <= n; ++i) 
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    return dp[n];
}

int climb2(int n, vector<int> const& cost) {
    if (n == 1 || n == 2) return cost[n];
    vector<int> dp(n + 1, 0);
    for (int i = 3; i <= n; ++i) 
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    return dp[n];
}

int climb3(int n, vector<int> const& cost) {
    if (n == 1 || n == 2) return cost[n];
    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; ++i) {
        int tmp = b;
        b = min(a, b) + cost[i];
        a = tmp;
    }
    return b;
}

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

int main() {
    int cur = 0;

    backtricking(choice, cur, 3, res);

    std::cout << res << std::endl;

    return 0;
}

void test() {
int a = 100;
int b = 200;


}