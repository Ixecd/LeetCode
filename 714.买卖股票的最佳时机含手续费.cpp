/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][0] = -prices[0];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1] - fee);
        }
        return dp[n][1];
    }
};
// @lc code=end

