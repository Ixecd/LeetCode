/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2) {
            dp[1][j] = -prices[0];
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 2 * k; j += 2) {
                dp[i][j + 1] =
                    max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i - 1]);
                dp[i][j + 2] =
                    max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i - 1]);
            }
        }
        return dp[n][k * 2];
    }
};

// @lc code=end
