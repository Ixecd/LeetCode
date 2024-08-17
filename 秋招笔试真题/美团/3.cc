#include <bits/stdc++.h>
#include <climits>
using ll = long long;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n, 0);
    vector<long long> prefix(n + 1, 0);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        prefix[i + 1] = sum;
    }
    int mei_left = 0;
    int mei_right = 0;
    int tuan_left = 0;
    int tuan_right = 0;
    long long mei_cmp = LLONG_MIN;
    long long tuan_cmp = LLONG_MAX;
    for (ll i = 0; i < prefix.size(); ++i) {
        for (ll j = i + 1; j < prefix.size(); ++j) {
            long long interval = prefix[j] - prefix[i];
            if (interval >= mei_cmp) {
                mei_cmp = interval;
                mei_left = i;
                mei_right = j - 1;
            }
            if (interval <= tuan_cmp) {
                tuan_cmp = interval;
                tuan_left = i;
                tuan_right = j - 1;
            }
        }
    }

    if (k <= 0) {
        for (int i = tuan_left; i <= tuan_right; ++i) {
            nums[i] *= k;
        }
    } else {
        for (int i = mei_left; i <= mei_right; ++i) {
            nums[i] *= k;
        }
    }
    // cout << "mei_left : " << mei_left << endl;
    // cout << "mei_right : " << mei_right << endl;
    mei_cmp = LLONG_MIN;
    tuan_cmp = LLONG_MAX;
    mei_left = 0;
    tuan_left = 0;
    mei_right = 0;
    tuan_right = 0;
    sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += nums[i];
        prefix[i + 1] = sum;
    }

    for (ll i = 0; i < prefix.size(); ++i) {
        for (ll j = i + 1; j < prefix.size(); ++j) {
            long long interval = prefix[j] - prefix[i];
            if (interval <= tuan_cmp) {
                tuan_cmp = interval;
                tuan_left = i;
                tuan_right = j - 1;
            }
            if (interval >= mei_cmp) {
                mei_cmp = interval;
                mei_left = i;
                mei_right = j - 1;
            }
        }
    }

    if (k <= 0) {
        for (int i = mei_left; i <= mei_right; ++i) {
            nums[i] *= k;
        }
    } else {
        for (int i = tuan_left; i <= tuan_right; ++i) {
            nums[i] *= k;
        }
    }
    // cout << "t_left : " << tuan_left << endl;
    // cout << "t_right : " << tuan_right << endl;
    sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    cout << sum;

    return 0;
}
