/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, k);
    }
private:
    int quickSelect(vector<int> &nums, int k) {
        int pivot = nums[rand() % nums.size()];
        vector<int> big, equal, small;
        for (int num : nums) {
            if (num > pivot) big.push_back(num);
            else if (num < pivot) small.push_back(num);
            else equal.push_back(num);
        }
        if (big.size() >= k) return quickSelect(big, k);
        else if (k > nums.size() - small.size()) return quickSelect(small, k - nums.size() + small.size());
        else return pivot;
    }
};


// @lc code=end
