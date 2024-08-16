/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        bool prevFlag = false;
        string res;
        int n = num1.size() - 1, m = num2.size() - 1;
        while (n >= 0 && m >= 0) {
            int a = num1[n] - '0';
            int b = num2[m] - '0';
            if (prevFlag == false) {
                if (a + b >= 10) {
                    prevFlag = true;
                } else {
                    prevFlag = false;
                }
                int c = (a + b) % 10;
                res += to_string(c);
            } else {
                if (a + b + 1 >= 10) {
                    prevFlag = true;
                } else {
                    prevFlag = false;
                }
                int c = (a + b + 1) % 10;
                res += to_string(c);
            }
            n--;
            m--;
        }
        while (n >= 0) {
            cout << prevFlag << " ";
            if (prevFlag == true) {
                if (num1[n] == '9') {
                    prevFlag = true;
                } else {
                    prevFlag = false;
                }
                int a = num1[n] - '0';
                cout << "a = " << a << endl;
                a += 1;
                a %= 10;
                res += to_string(a);
                n--;
            } else {
                res += num1[n--];
            }
        }
        while (m >= 0) {
            if (prevFlag == true) {
                if (num2[m] == '9') {
                    prevFlag = true;
                } else {
                    prevFlag = false;
                }
                int a = num2[m] - '0';
                a += 1;
                a %= 10;
                res += to_string(a);
                m--;
            } else {
                res += num2[m--];
            }
        }
        if (prevFlag) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// @lc code=end
