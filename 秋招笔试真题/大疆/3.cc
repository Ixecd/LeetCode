#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 01 -> 10 同时
int main() {
    string s;
    cin >> s;
    ll cnt = 0;
    ll first_zero = 0, last_zero = 0;
    ll cnt_zero = 0;
    bool first = false;
    for (ll i = 0; i < s.size(); ++i) {
        if (s[i] == '0' && first == false) {
            first = true;
            first_zero = i;
            cnt_zero++;
        } else if (s[i] == '0' && first == true) {
            last_zero = i;
            cnt_zero++;
        }
    }
    cout << last_zero - cnt_zero + 1;
    // for (auto &[x, y]: orz) {
    //     cout << x << ',' << y << endl;
    // }

    return 0;
}
