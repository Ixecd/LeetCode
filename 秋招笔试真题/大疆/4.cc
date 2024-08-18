#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 01 -> 10 同时
int main() {
    string s;
    cin >> s;
    vector<int> dp(s.size() + 1, 0);
    if (s[0] == '0' && s[1] == '1') dp[2] = 1;
    else dp[2] = 0;
    for (int i = 3; i <= s.size(); ++i) {
        if (s[i - 1] == '1') dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1];
    }
    cout << dp[s.size()];
    return 0;
}
