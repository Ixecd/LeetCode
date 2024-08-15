/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int cnt = 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n && obstacleGrid[i - 1][0] != 1; ++i) dp[i][1] = 1;
        for (int j = 1; j <= m && obstacleGrid[0][j - 1] != 1; ++j) dp[1][j] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                if (obstacleGrid[i - 1][j - 1] != 1) 
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

