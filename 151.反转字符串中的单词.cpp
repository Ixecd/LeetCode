/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // 别tm低级模拟了
        if (s.size() == 0) {
            return s;
        }
        stack<string> st;
        string result;
        for (int i = 0; i < s.size(); ++i) {
            string word;
            if (s[i] == ' ') {
                continue;
            }
            while (i < s.size() && s[i] != ' ') {
                word += s[i++];
            }
            st.push(word);
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) {
                result += " ";
            }
        }
        return result;
    }
};

// @lc code=end
