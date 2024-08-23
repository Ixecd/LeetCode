/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        for (int i = 1, j, len = digits.size(), lmt = INT_MAX / 10; i < len;
             ++i) {
            if (digits[i - 1] > digits[i]) {
                j = 0;
                while (digits[j] <= digits[i]) {
                    ++j;
                }
                swap(digits[j], digits[i]);
                sort(begin(digits), begin(digits) + i);
                while (digits.size()) {
                    n = n * 10 + digits.back();
                    digits.pop_back();
                    if (n >= lmt && digits.size()) {
                        return -1;
                    }
                }
                return n;
            }
        }
        return -1;
    }
};

// @lc code=end
