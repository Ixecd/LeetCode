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
        if (cur + choice[i] > n) {
            continue;
        }
        backtricking(choice, cur + choice[i], n, res);
    }
}

int climb(int n, vector<int> const &cost) {
    if (n == 1 || n == 2) {
        return cost[0];
    }
    vector<int> dp(n + 1, 0);
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
}

int climb2(int n, vector<int> const &cost) {
    if (n == 1 || n == 2) {
        return cost[n];
    }
    vector<int> dp(n + 1, 0);
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}

int climb3(int n, vector<int> const &cost) {
    if (n == 1 || n == 2) {
        return cost[n];
    }
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
    for (int i = 2; i <= n; ++i) {
        dp[i][1] += dp[i - 1][1] + grid[i - 1][0];
    }
    for (int j = 2; j <= m; ++j) {
        dp[1][j] += dp[1][j - 1] + grid[0][j - 1];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    cout << dp[n][m] << endl;
}

int charge(vector<int> const &coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int j = 0; j <= target; ++j) {
        dp[0][j] = 0x3f3f3f3f;
    }
    for (int i = 1; i <= n; ++i) {
        for (int c = 1; c <= target; ++c) {
            if (c - coins[i - 1] >= 0) {
                dp[i][c] = min(dp[i - 1][c], dp[i][c - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][target];
}

int sol(vector<int> const &coins, int target) {
    int n = coins.size();
    vector<int> dp(target + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int c = 1; c <= target; ++c) {
            if (c - coins[i - 1] >= 0) {
                dp[c] = min(dp[c], dp[c - coins[i - 1]] + 1);
            }
        }
    }
    return dp[target];
}

int charge2(vector<int> const &coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    // 初始化dp
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1; // 当金额为0时,组合数量为1
    }
    for (int j = 0; j <= target; ++j) {
        dp[0][j] = 0; // 当硬币数量为0时,组合数量为0
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j - coins[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int charge2_(vector<int> const &coins, int target) {
    int n = coins.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j - coins[i - 1] >= 0) {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            } else {
                dp[j] = dp[j];
            }
        }
    }
    return dp[target];
}

int LSA(string const &s, string const &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 注意初始化dp
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] =
                    min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
    }
    return dp[n][m];
}

int main() {
    // int cur = 0;

    // backtricking(choice, cur, 3, res);

    // std::cout << res << std::endl;
    // vector<int> coins{1, 2, 5};
    // std::cout << sol(coins, 15);

    // std::cout << charge2_(coins, 5);

    string s = "bag";
    string t = "pack";
    std::cout << LSA(s, t);

    return 0;
}
