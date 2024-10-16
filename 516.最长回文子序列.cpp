/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) dp[i][i] = 1;
        for (int i = n; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

