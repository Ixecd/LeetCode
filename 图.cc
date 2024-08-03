#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<bool> vis(n, false);
vector<vector<int>> res;
vector<int> path;
void dfs(vector<vector<int>> &A, int from, int to) {
    if (from == to) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < n; ++i) 
        if (from != i && A[from][i] != 0 && vis[i] == 0) {
            path.push_back(i);
            vis[i] = 1;
            dfs(A, i, to);
            vis[i] = 0;
            path.pop_back();
        }
}

int main() {

    return 0;
}