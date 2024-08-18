#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {

    ll times;
    cin >> times;
    unordered_map<ll, ll> down;
    for (ll i = 0; i < times; ++i) {
        ll id;
        cin >> id;
        down[id]++;
    }
    cin >> times;
    unordered_map<ll, ll> up;
    for (ll i = 0; i < times; ++i) {
        ll id;
        cin >> id;
        down[id]--;
    }
    vector<ll> res(15, 0);
    for (auto &[ap_id, num] : down) {
        if (num >= 1 && num <= 15) res[num - 1]++;
    }

    for (int num : res) 
        cout << num << ' ';

    return 0;
}