/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int robHelper(vector<int> &nums, int left, int right) {
        int pre = 0, cur = 0;
        for (int i = left; i <= right; ++i) {
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return n ? nums[n] : 0;
        }
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }
};

// @lc code=end
