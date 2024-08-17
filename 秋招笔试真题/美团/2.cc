#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<long long> nums(n , 0);
    vector<unsigned long long> prefix(n + 1, 0);
    unsigned long long pre = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        pre += nums[i];
        prefix[i + 1] = pre;
    }
    int avg = prefix[n] / n;
    long long lessCount = 0;
    long long moreCount = 0;
    for (unsigned long long num : nums) {
        if (num < avg) lessCount += avg - num;
        else if (num > avg) moreCount += num - avg;
    }
    cout << min(lessCount, moreCount);

    return 0;
}