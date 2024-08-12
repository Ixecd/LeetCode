#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 给定n个作业，作业有开始时间和需要的时间，求最小总作业消耗时间，单个作业消耗时间是作业完成时间减去作业开始时间,作业可以分开执行
// 第i份作业的完成耗时为最终完成时刻减去作业被布置的时刻t
// 默认给定的作业开始的时间顺序是严格从小到大的
int main() {

    ll n;
    cin >> n;
    vector<pair<ll,ll>> vp(n);
    for (ll i = 0; i < n; ++i) cin >> vp[i].first >> vp[i].second;
    // 需要的时间从小到大排序
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = 0;
    // 把第一个的需要时间添加进去
    pq.push(vp[0].second);
    for (ll i = 1; i < n; ++i) {
        // d 表示当前hw和前一个hw的开始时间的差值.这里必然>=0
        ll d = vp[i].first - vp[i - 1].first;
        while (pq.size() && d) {
            // 队列中有任务,并且当前任务和前面的任务有差值
            auto x = pq.top(); pq.pop();
            ll dis = min(x, d);
            // 队列中的所有任务都是可以在当前dis期间执行的,但是只能执行一个任务
            // 意味着其它可以执行的任务需要等待dis时间
            // 所以 ans += dis -> 表示当前任务需要消耗的时间
            // ans += dis * pq.size() -> 表示任务队列中的任务需要等待的时间
            ans += dis * (pq.size() + 1);
            x -= dis;
            d -= dis;
            if (x) pq.push(x);
        }
        pq.push(vp[i].second);
    }
    while (pq.size()) {
        auto x = pq.top(); pq.pop();
        ans += x * (pq.size() + 1);
    }
    cout << ans << endl;
    return 0;
}