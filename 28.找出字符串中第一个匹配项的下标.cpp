/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    const int N = 1e4 + 10;
    void getNext(string &s, int next[]) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) ++j;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        int next[N];
        getNext(needle, next);
        int i = 0, j = 0;
        while (i < haystack.size()) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) ++j;
            ++i;
            if (j == needle.size()) return i - j;
        }
        return -1;
    }
};
// @lc code=end

