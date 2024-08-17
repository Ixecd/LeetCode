#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> up(n + 1, 0);
    vector<int> down(m + 1, 0);
    vector<int> total(m + n, 0);
    for (int i = 0; i < n; ++i) 
        cin >> up[i];
    for (int j = 0; j < m; ++j) {
        cin >> down[j];
        total[j] = up[j] + down[j];
    }
    int result = max(m, n);
    cout << result;

    return 0;
}