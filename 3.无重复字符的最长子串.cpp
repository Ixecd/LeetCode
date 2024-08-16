/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char -> [-128, 127]
        vector<int> dict(256, - 1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (dict[s[i]] > start) start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// @lc code=end
