#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 前缀和

int main() {
    int a, b;
    long long result = 0;
    cin >> a >> b;
    int len = 100000;
    vector<long long> prefix(len, 0);
    ll pre = 0;
    for (int i = 1; i <= len; ++i) {
        pre += i;
        prefix[i] = pre;
    }
    long long res1 = 0;
    long long res2 = 0;
    for (int i = 2; i < prefix.size(); ++i) {
        if (a > prefix[i]) continue;
        res1 = prefix[i] - a;
        int j = i + 1;
        if (b > prefix[j]) continue;
        res2 = prefix[j] - b;
        if (res1 == res2) {
            cout << res1;
            return 0;
        }
        
    }
    return 0;
}
