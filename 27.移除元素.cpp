/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) continue;
            else swap(nums[i], nums[index++]);
        }
        return index;
    }
};
// @lc code=end

