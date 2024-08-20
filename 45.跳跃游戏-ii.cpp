/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int> &nums) {
        int curJump = 0, nxtJump = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            nxtJump = max(nxtJump, i + nums[i]);
            if (curJump == i) {
                cnt++;
                curJump = nxtJump;
            }
        }
        return cnt;
    }
};

// @lc code=end
