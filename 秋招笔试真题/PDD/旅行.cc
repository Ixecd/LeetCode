#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 给定n个旅行计划，每个旅行计划完成的时间只能是xi,xi+d,xi+2d,...，并且每天最多只能完成一个旅游，求最小时间
// 并且只能按照给定的优先级顺序来进行旅行

int main() {

    ll n;
    cin >> n;
    vector<vector<ll>> data(n, vector<ll>(3));
    for (ll i = 0; i < n; ++i) 
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    // 按照p从小到大进行排序
    sort(data.begin(), data.end());
    ll result = 1;
    for (ll i = 0; i < n; ++i) {
        vector<ll> current = data[i];
        if (result < current[1]) result = current[1];
        else {
            ll day = current[1];// 首次预约时间
            // 下面的计算是很耗时的,对于这种while循环来说最好直接使用数学计算
            // while (result > current[1]) current[1] += current[2];
            ll dis = result - day;// 上一次记录的时间和首次预约时间的差值
            ll b = dis/current[2] + (dis%current[2] > 0);
            // 这里保存的 result,其实是前一天的,所以下面的b要多+1
            if (day + b * current[2] == result) ++b;
            result = day + b * current[2];
        }
    }
    cout << result << endl;

    return 0;
}
// 总结:不用struct,因为只有三个变量 vector<vector<ll>>就可以
// result 记录的永远都是上一天的时间,如果today >= current[1]表明当前景点应该在之前就应该被访问,但是没有,所以通过Math求b