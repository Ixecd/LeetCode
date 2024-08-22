/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][i] = true;
        }
        string ans = "";
        ans += s[0];
        for (int i = n; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1]) {
                    if (j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (ans.size() < j - i + 1) {
                            ans = s.substr(i - 1, j - i + 1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end
