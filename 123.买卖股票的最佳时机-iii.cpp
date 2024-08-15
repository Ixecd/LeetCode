/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        dp[1][1] = -prices[0];
        dp[1][3] = -prices[0];
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 4; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i - 1]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i - 1]);
            }
        }
        return dp[n][4];
    }
};
// @lc code=end

