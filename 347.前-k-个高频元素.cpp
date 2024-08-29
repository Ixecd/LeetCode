/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    struct Cmp {
        bool operator()(pair<int, int> &l, pair<int, int> &r) {
            return l.second > r.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ans;
        unordered_map<int, int> umap;
        for (int num: nums) {
            umap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        for (auto [x, y]: umap) {
            pq.push({x, y});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

// @lc code=end
