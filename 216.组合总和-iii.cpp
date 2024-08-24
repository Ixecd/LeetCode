/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int k, int n, int curSum, int start) {
        if (curSum == n && k == 0) {
            ans.push_back(path);
            return;
        } else if (curSum > n || k < 0) return;
        for (int i = start; i <= 9; ++i) {
            path.push_back(i);
            dfs(k - 1, n, curSum + i, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 0, 1);
        return ans;
    }
};

// @lc code=end
