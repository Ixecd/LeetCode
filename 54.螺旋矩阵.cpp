/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // 从矩阵到数组四个变量
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                for (int i = right - 1; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                for (int i = bottom - 1; i > top; --i) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return ans;
    }
};

// @lc code=end
