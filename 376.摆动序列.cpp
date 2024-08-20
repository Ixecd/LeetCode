/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int curDiff = 0;
        int preDiff = 0;
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            curDiff = nums[i] - nums[i - 1];
            if ((curDiff > 0 && preDiff <= 0) ||
                (curDiff < 0 && preDiff >= 0)) {
                ans++;
                preDiff = curDiff;
            }
        }
        return ans;
    }
};

// @lc code=end
