/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][1] = nums[0];
        dp[2][1] = max(nums[0], nums[1]);
        dp[2][0] = nums[0];
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 2][1], dp[i - 1][0]) + nums[i - 1];
        }
        return max(dp[n][1], dp[n][0]);
    }
};

// @lc code=end
