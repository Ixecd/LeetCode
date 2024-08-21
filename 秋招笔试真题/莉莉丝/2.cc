#include <bits/stdc++.h>
using namespace std;
// Hard 信封嵌套 -> LC354
// 70%
int main() {

    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) 
        cin >> nums[i][0] >> nums[i][1];
    sort(nums.begin(), nums.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int cnt = 0;
    int pre_x = 0x3f3f3f3f, pre_y = 0x3f3f3f3f;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i][0] < pre_x && nums[i][1] < pre_y) {
            cnt++;
            pre_x = nums[i][0];
            pre_y = nums[i][1];
        }
    }
    cout << cnt << endl;
    return 0;
}