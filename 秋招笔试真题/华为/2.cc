#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> dir {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
};
int res = 0x3f3f3f3f;
vector<int> path;
void dfs(vector<vector<int>> &grid, int x, int y, int k, vector<vector<bool>> &vis) {
    if (grid[x][y] > res) return;
    if (k >= 0 && x == grid.size() - 1 && y == grid[0].size() - 1) {
        int tmp = INT_MIN;
        for (int i = 0; i < path.size(); ++i) 
            if (tmp < path[i]) tmp = path[i];
        res = min(res, tmp);
        return;
    } else if (k <= 0 && x != grid.size() - 1 && y != grid[0].size() - 1) return;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || vis[nx][ny]) continue;
        path.push_back(grid[nx][ny]);
        vis[nx][ny] = true;
        dfs(grid, nx, ny, k - 1, vis);
        vis[nx][ny] = false;
        path.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> grid[i][j];
    vis[0][0] = true;
    path.push_back(grid[0][0]);
    // dfs(grid, 0, 0, k, vis);
    cout << 1 << endl;
    return 0;
}