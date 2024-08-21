/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ans = 0;
        int n1 = version1.size(), n2 = version2.size();
        for (int i = 0, j = 0; i < n1 || j < n2; ++i,++j) {
            string s1 = "", s2 = "";
            while (i < n1 && version1[i] != '.') {
                if (s1.size() == 0 && version1[i] == '0') {
                    ++i; continue;
                }
                s1 += version1[i++];
            }
            while (j < n2 && version2[j] != '.') {
                if (s2.size() == 0 && version2[j] == '0') {
                    ++j; continue;
                }
                s2 += version2[j++];
            }
            if (s1.size() < s2.size()) return -1;
            else if (s1.size() > s2.size()) return 1;
            ans = s1.compare(s2);
            if (ans < 0) return -1;
            else if (ans > 0) return 1;
        }
        return 0;
    }
};
// @lc code=end

