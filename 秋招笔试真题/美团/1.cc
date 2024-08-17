#include <bits/stdc++.h>
using ll = long long;
using namespace std;
// gcd
vector<int> ss;
vector<bool> isValid(1000001, true);
bool is_ss(int num) {
    if (isValid[num] == false) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            for (int j = i; j < 1000001; j += i) 
                isValid[j] = false;
            return false;
        }
    }
    return true;
}
void build_ss() {
    for (int i = 2; i < 1000001; ++i) {
        if (is_ss(i)) {
            ss.push_back(i);
        }
    }
}

int gcd(int n) {
    for (int i = 0; i < ss.size(); ++i) {
        if (n % ss[i] == 0) return ss[i];
    }
    return -1;
}

int main() {
    build_ss();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << gcd(n) << endl;
    }

    return 0;
}