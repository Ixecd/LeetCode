/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')' && !st.empty()) {
                char c = st.top();
                st.pop();
                if (c != '(') {
                    return false;
                }
            } else if (s[i] == '}' && !st.empty()) {
                char c = st.top();
                st.pop();
                if (c != '{') {
                    return false;
                }
            } else if (s[i] == ']' && !st.empty()) {
                char c = st.top();
                st.pop();
                if (c != '[') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return st.size() == 0;
    }
};

// @lc code=end
