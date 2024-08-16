/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int> &nums, int curSum, int target, int index) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            curSum += nums[i];
            dfs(nums, curSum, target, i);
            curSum -= nums[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int curSum = 0;
        dfs(candidates, curSum, target, 0);
        return ans;
    }
};

// @lc code=end
