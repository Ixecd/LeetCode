/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    const int N = 1e4 + 10;
    bool repeatedSubstringPattern(string s) {
        int next[N];
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) ++j;
            next[i] = j;
        }
        int L = s.size(), n = next[s.size() - 1];
        if ((L % (L - n) == 0) && n > 0) return true;
        return false;
    }
};
// @lc code=end

