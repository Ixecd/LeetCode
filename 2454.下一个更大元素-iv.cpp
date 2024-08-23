/*
 * @lc app=leetcode.cn id=2454 lang=cpp
 *
 * [2454] 下一个更大元素 IV
 */
#include <bits/stdc++.h>
using namespace std;
// 下两个更大的数
// @lc code=start
class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> s1, s2, tmp;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                ans[s2.top()] = nums[i];
                s2.pop();
            }
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                tmp.push(s1.top());
                s1.pop();
            }
            while (!tmp.empty()) {
                s2.push(tmp.top());
                tmp.pop();
            }
            s1.push(i);
        }
        return ans;
    }
};

// @lc code=end
