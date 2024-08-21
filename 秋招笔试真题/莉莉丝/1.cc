#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) 
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    int left = 0;
    int ans = 0;
    for (int i = 1; i < nums.size(); ++i) {
        int curDiff = nums[i] - nums[left];
        if (curDiff > k) left++;
        else ans = max(ans, i - left + 1);
    }

    cout << ans;

    return 0;
}
// 64 位输出请用 printf("%lld")