/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n == 1) return x;
        bool flag = false;
        if (n < 0) flag = true;
        long long n_1 = abs(n);
        double res = 1;
        while (n_1) {
            if (n_1 & 1) res *= x;
            x *= x;
            n_1 >>= 1;
        }
        if (flag) return 1 / res;
        return res;
    }
};
// @lc code=end

