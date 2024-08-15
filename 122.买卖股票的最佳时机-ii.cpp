/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][0] = -prices[0];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
        }
        return dp[n][1];
    }
};
// @lc code=end

