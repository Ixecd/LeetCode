/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        unordered_map<int, int> umap; // key->a+b, value->times
        for (int a: nums1) {
            for (int b: nums2) {
                umap[a + b]++;
            }
        }
        int cnt = 0;
        for (int c: nums3) {
            for (int d: nums4) {
                int cur = -c - d;
                cnt += umap[cur];
            }
        }

        return cnt;
    }
};

// @lc code=end
