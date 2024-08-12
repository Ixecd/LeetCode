#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 哈希函数为f = x % n ,
// 给定一个插入完成的哈希表，要求还原插入顺序，如果多个可能，还原字典序最小的

// 可以拓扑也可以并查集
// 坐标从0开始直接用的树状数组
template <typename T>
class Fenwick {
private:
    int n;
    vector<T> c;

    int lowbits(int x) {
        return (-x) & x;
    }

    int pre_sum(int i) {
        int re = 0;
        for (; i > 0; i -= lowbits(i)) {
            re += c[i];
        }
        return re;
    }

public:
    explicit Fenwick<T>(vector<T> v) {
        this->n = v.size();
        this->c = vector<T>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    };

    void add(int i, int val) {
        ++i;
        for (; i <= n; i += lowbits(i)) {
            c[i] += val;
        }
    }

    int range_sum(int i, int j) {
        ++i;
        ++j;
        return pre_sum(j) - pre_sum(i - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        } else if (a[i] % n == i) {
            pq.push({a[i], i});
            mp[a[i]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }

    vector<int> b = a;
    for (int &x: b) {
        if (x) {
            x = 1;
        }
    }
    Fenwick<int> fw(b);

    vector<int> ans;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int x = p.first, pos = p.second;
        ans.push_back(x);
        fw.add(pos, -1);
        fw.add(pos + n, -1);
        int l = pos, r = 2 * n;
        while (l + 1 != r) {
            int m = l + r >> 1;
            if (fw.range_sum(pos, m) == 0) {
                l = m;
            } else {
                r = m;
            }
        }
        l++;
        if (l < 2 * n && fw.range_sum(pos, l) == 1) {
            if (mp[a[l]]) {
                continue;
            }
            int lp = a[l] % n;
            if (lp > l) {
                l += n;
            }
            if (fw.range_sum(lp, l - 1) == 0) {
                mp[a[l]] = 1;
                if (l >= n) {
                    l -= n;
                }
                pq.push({a[l], l});
            }
        }
    }
    for (int x: ans) {
        cout << x << " ";
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
}
