/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            curSum += nums[i];
            dfs(nums, curSum, target, i + 1);
            curSum -= nums[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        int curSum = 0;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, curSum, target, 0);
        return ans;
    }
};

// @lc code=end
