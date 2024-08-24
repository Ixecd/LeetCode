/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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
        for (int i = startIndex; i < nums.size(); ++i) {
            // used[i - 1] == false -> 同一树层, used[i - 1] == true -> 同一树枝
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            // used[i] = true;
            dfs(nums, i + 1);
            // used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};

// @lc code=end
