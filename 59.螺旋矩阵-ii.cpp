/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int loop = n / 2, offset = 0;
        int start_x = 0, start_y = 0;
        int count = 1;
        while (loop--) { //[)

            for (int i = start_y; i < n - offset - 1; ++i) 
                ans[start_x][i] = count++;
            
            for (int i = start_x; i < n - offset - 1; ++i)
                ans[i][n - offset - 1] = count++;
            
            for (int i = n - offset - 1; i > start_y; --i)
                ans[n - offset - 1][i] = count++;
            
            for (int i = n - offset - 1; i > start_x; --i)
                ans[i][offset] = count++;

            offset += 1;
            start_x += 1;
            start_y += 1;
        }
        if (n % 2) ans[n/2][n/2] = count;
        return ans;
    }
};
// @lc code=end

