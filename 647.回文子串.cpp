/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = n;
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        // for (int i = 1; i <= n; ++i) dp[i][i] = true;
        for (int i = n; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

