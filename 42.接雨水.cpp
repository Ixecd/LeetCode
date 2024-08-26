/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        int ans = 0;
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        for (int i = 0; i < n; ++i) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            ans += count > 0 ? count : 0;
        }
        return ans;
    }
};

// @lc code=end