/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */


#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ans = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
            ++right;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

