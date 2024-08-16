/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int left, right = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0 || (i > 0 && nums[i] == nums[i - 1])) {
                continue;
            }
            left = i + 1, right = n - 1;
            while (left < right) {
                int curSum = nums[i] + nums[left] + nums[right];
                if (curSum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                } else if (curSum > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return ans;
    }
};

// @lc code=end
