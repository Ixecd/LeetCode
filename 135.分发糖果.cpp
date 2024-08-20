/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candyAry(ratings.size(), 1);
        for (int i = 1; i < candyAry.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candyAry[i] = candyAry[i - 1] + 1;
            }
        }
        for (int i = candyAry.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candyAry[i] = max(candyAry[i], candyAry[i + 1] + 1);
            }
        }
        int cnt = 0;
        for (int num: candyAry) {
            cnt += num;
        }
        return cnt;
    }
};

// @lc code=end
