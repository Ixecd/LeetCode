#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//给一个01串，你可以最多选择一个区间进行反转，0->1 , 1->0 ,求最终abs(cnt[0]-cnt[1])的可能数

//每次延长我们的[l,r]区间一次，cnt[0] - cnt[1] 要么+1，要么-1，所以我们可以求一个区间，使得cnt[0] - cnt[1] 最大或者最小，这个可以使用前缀
// 和解决，那么对于最大的cnt[0] - cnt[1] ， 一定可以每次+2到达，所以沿途的数字都可以到达


int main() {

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) cin >> num;
    // 技巧将所有的0都变为-1,之后就不需要统计数量,两者之和就是差值
    for (int& num : nums) if (num == 0) num = -1;
    
    int prmi = 0, prmx = 0;
    int pr = 0;
    int mx = 0, mi = 0;
    for (int i = 0; i < n; ++i) {
        pr += nums[i];
        mx = max(mx, pr - prmi);
        mi = min(mi, pr - prmx);
        prmx = max(prmx, pr);
        prmi = min(prmi, pr);
    }
    set<int> se;
    int sm = accumulate(nums.begin(), nums.end(), 0);
    for (int i = sm - 2 * mx; i <= sm - 2 * mi; i += 2) 
        se.insert(abs(i));
    cout << se.size() << endl;

    return 0;
}