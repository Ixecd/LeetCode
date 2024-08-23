/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool flag = true;
        int ans = 0;
        int i = 0;
        while (i < s.size() && isspace(s[i])) ++i;
        if (s[i] == '+') flag = true, ++i;
        else if (s[i] == '-' ) flag = false, ++i;
        while (isdigit(s[i])){
            int n = s[i] - '0';
            if (ans > (INT_MAX - n) / 10) {
                if (flag == true) return INT_MAX;
                else return INT_MIN; 
            }
            ans *= 10;
            ans += n;
            ++i;
        }
        if (flag == false) return -ans;
        return ans;
    }
};
// @lc code=end

