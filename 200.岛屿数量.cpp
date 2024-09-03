/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int ary[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int BFS(vector<vector<char>> &grid, int x, int y,
            vector<vector<bool>> &vis) {
        queue<pair<int, int>> que;
        que.push({x, y});
        int n = grid.size(), m = grid[0].size();
        vis[x][y] = true;
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                x = que.front().first;
                y = que.front().second;
                que.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + ary[i][0];
                    int ny = y + ary[i][1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                        vis[nx][ny] == true || grid[nx][ny] == '0') {
                        continue;
                    }
                    vis[nx][ny] = true;
                    que.push({nx, ny});
                }
            }
        }
        return 1;
    }

    int numIslands(vector<vector<char>> &grid) {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j] == false && grid[i][j] == '1') {
                    cnt += BFS(grid, i, j, vis);
                }
            }
        }
        return cnt;
    }
};

// @lc code=end
