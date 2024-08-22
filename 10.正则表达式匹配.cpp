/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // s是目标串,p是表达式
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        auto matches = [&](int x, int y) {
            if (x == 0) {
                return false;
            }
            if (p[y - 1] == '.') {
                return true;
            }
            return s[x - 1] == p[y - 1];
        };
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    if (matches(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                } else if (matches(i, j)) {
                    dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

// @lc code=end
