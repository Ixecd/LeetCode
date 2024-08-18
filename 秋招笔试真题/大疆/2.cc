#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 01 -> 10 同时
int main() {
    string s;
    cin >> s;
    ll cnt = 0;
    vector<pair<int, int>> orz;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '1' && s[i - 1] == '0') {
            orz.push_back({i - 1, i});
        }
    }
    // for (auto &[x, y]: orz) {
    //     cout << x << ',' << y << endl;
    // }
    while (true) {
        cnt++;
        for (auto &[x, y]: orz) {
            s[x] = '1';
            s[y] = '0';
        }
        orz.clear();
        bool change = false;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1' && s[i - 1] == '0') {
                orz.push_back({i - 1, i});
                change = true;
            }
            if (i == s.size() - 1 && change == false) {
                cout << cnt;
                return 0;
            }
        }
    }

    return 0;
}
