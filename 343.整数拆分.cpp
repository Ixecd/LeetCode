/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    unsigned long long q_pow(unsigned long long n, int p) {
        unsigned long long result = 1;
        if (p == 0) {
            return result;
        }
        while (p > 0) {
            if (p & 1) {
                result = result * n;
            }
            p >>= 1;
            n *= n;
        }
        return result;
    }

    int integerBreak(int n) {
        if (n <= 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }
        int a = n / 3;
        int b = n % 3;
        if (b == 1) {
            return q_pow(3, a - 1) * 2 * 2;
        } else if (b == 2) {
            return q_pow(3, a) * 2;
        }
        return q_pow(3, a);
    }
};

// @lc code=end
