#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 回家过年
int cnt = 0;
int cst = 0;
int edge = 0;
vector<vector<pair<int, int>>> gra(100 + 1, vector<pair<int, int>>(100, {0x3f3f3f3f, 0}));

vector<int> path;
vector<bool> vis(1000 + 1, false);

void dfs(int start, int end, int cost) {
    if (start == end && cost == cst) {
        unsigned long long res = 1;
        for (int i = 0; i < path.size(); ++i) 
            res *= path[i];
        cnt += res;
    }
    for (int i = 1; i <= edge; ++i) {
        if (start == i || vis[i]) continue;
        auto c = gra[start][i].first;
        if (c == 0x3f3f3f3f) continue;
        path.push_back(gra[start][i].second);
        vis[i] = true;
        dfs(i, end, cost + c);
        vis[i] = false;
        path.pop_back();
    }
}

int main() {

    int n, m, a;
    cin >> n >> m >> a;
    cst = a;
    edge = n;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        gra[u][v].first = w;
        gra[u][v].second += 1;
    }
    vis[1] = true;
    dfs(1, n, 0);

    if (cnt >= 20220201) cout << "All roads lead to Home!" << endl;
    // cout << "All roads lead to Home!" << endl;
    cout << cnt % 20220201;

    return 0;
}