/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // int cnt = n;
        // unsigned long long fz = 1, fm = 1;
        // while (cnt) {
        //     fm *= cnt--;
        // }
        // cnt = n + n;
        // int t = n;
        // while (t--) {
        //     fz *= cnt--;
        // }
        // cout << "fm = " << fm << endl;
        // cout << "fz = " << fz << endl;
        // cout << "n = " << n << endl;
        // return 1ull * fz / ((n + 1) * fm);
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return C;
    }
};

// @lc code=end
