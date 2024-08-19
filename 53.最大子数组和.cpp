/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int res = INT_MIN;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += nums[i];
            res = max(res, count);
            if (count < 0) {
                count = 0;
            }
        }
        return res;
    }
};

// @lc code=end
