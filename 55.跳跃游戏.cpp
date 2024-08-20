/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curJump = 0;
        for (int i = 0; i <= curJump; ++i) {
            curJump = max(curJump, i + nums[i]);
            if (curJump >= nums.size() - 1) return true;
        }
        return false;
        
    }
};
// @lc code=end

