/**
 * 08.10 美团 T2
 * 小美有一个长度为n的数组a,他可以对数组进行如下操作：
 * 删除第一个元素a1, 同时数组的长度减 1，花费为x.
 * 删除整个数组，花费为k *
 * MEX(a)（其中MEX(a)表示a中未出现过的最小非负整数。例如[0,1,2,4]的MEX为3）。
 * 小美想知道将a数组全部清空的最小代价是多少, 请你帮帮他吧.
 */
#include <bits/stdc++.h>
using namespace std;

/// 第一行为 T 表次数
/// 第二行 n, k, x, n数组大小,k删除整个的花费系数,x删除单个元素花费系数 10^9 -->
/// 10亿 uint_t Max -> 42亿 第三行 n 个整数,表示数组元素之和

// 缺失的第一个非负整数
int firstMissingPosAndZero(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
            swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    return n;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        long long res = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            vector<int> copy(n - i, 0);
            copy.assign(nums.begin() + i, nums.end());
            int mex = firstMissingPosAndZero(copy);
            cout << "mex = " << mex << endl;
            res = min(res, 0ll + i * x + mex * k);
        }
        cout << res << endl;
    }
    return 0;
}
