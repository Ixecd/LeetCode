#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << 0 << ' ';
            continue;
        }
        if (n == 2) {
            cout << m << ' ';
            continue;
        }
        ll ans = m;
        ll times = n - 2;
        if (m % times) {
            ll diff = m / times;
            ans = diff * (times + 1);
            ans += 2 * (m % times);
            cout << max(ans, 2 * m) << ' ';
        } else {
            ll diff = m / times;
            ans = diff * (times + 1);
            cout << max(ans, 2 * m) << ' ';
        }
    }
    return 0;
}
