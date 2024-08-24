#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> apple(n, 0);
        int max_apple = INT_MIN;
        int max_candy = INT_MIN;
        vector<int> candy(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> apple[i];
            max_apple = max(max_apple, apple[i]);
        } 
            
        for (int i = 0; i < n; ++i) {
            cin >> candy[i];
            max_candy = max(max_candy, candy[i]);
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (apple[i] <= max_apple && candy[i] <= max_candy) {
                int diff1 = max_apple - apple[i];
                int diff2 = max_candy - candy[i];
                res += min(diff1, diff2) + abs(diff1 - diff2);
            }
        }
        cout << res << endl;

    }

    return 0;
}
// 64 位输出请用 printf("%lld")