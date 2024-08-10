/**
 * @brief
 * 小美准备登录美团, 需要输入密码, 小美忘记了密码, 只记得密码可能是  n
个字符串中的一个。小美会按照密码的长度从小到大依次尝试每个字符串,
对于相同长度的字符串, 小美随机尝试, 并且相同的密码只会尝试一次。小美想知道,
她最少需要尝试多少次才能登录成功, 最多需要尝试多少次才能登录成功。
小美不会重新尝试已经尝试过的字符串。成功登录后会立即停止尝试。
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> st;
    int low = 0, high = 0;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        int sz = str.size();
        if (sz > s.size() || st.count(str)) {
            continue;
        } else {
            st.insert(str);
            if (sz < s.size()) {
                low++;
            } else {
                high++;
            }
        }
    }
    // int low = 0, high = 0;
    // for (auto it = mp.begin(); it != mp.end(); ++it) {
    //     if ((*it).first < s.size()) low += (*it).second;
    //     if ((*it).first <= s.size()) high += (*it).second;
    // }
    high += low;
    low += 1;
    std::cout << low << " " << high << std::endl;

    return 0;
}
