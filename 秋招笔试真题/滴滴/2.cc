#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i) 
        for (int j = 0; j < k; ++j) 
            cin >> nums[i][j];
    string str;
    cin >> str;
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n; i += 1) 
        dp[i][i + 1] = nums[str[i - 1] - 'a'][str[i] - 'a'];
    
    for (int i = n; i >= 1; --i) {
        for (int j = i + 1; j <= n; j += 2) {
            dp[i][j] = max(dp[i][j], nums[str[i - 1] - 'a'][str[j - 1] - 'a'] + dp[i + 1][j - 1]);
        }
    }
    
    cout << dp[1][n] << endl;
    
    return 0;
}