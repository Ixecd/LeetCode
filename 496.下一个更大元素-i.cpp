/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (nums1[i] == nums2[j]) {
                    ++j;
                    while (j < m && nums2[j] < nums1[i]) ++j;
                    if (j == m) ans.push_back(-1);
                    else ans.push_back(nums2[j]);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

