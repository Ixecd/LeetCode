/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][0] = -prices[0];
        dp[2][0] = max(dp[1][0], -prices[1]);
        dp[2][1] = max(dp[2][1], prices[1] + dp[1][0]);
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], prices[i - 1] + dp[i - 1][0]);
        }
        return dp[n][1];
    }
};

// @lc code=end
