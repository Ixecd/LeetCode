/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int> &nums, int startIndex) {
        ans.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(nums, 0);
        return ans;
    }
};

// @lc code=end
