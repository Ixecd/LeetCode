/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> res;
    vector<string> path;
    void dfs(string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if (isValid(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else continue;
            dfs(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};
// @lc code=end

