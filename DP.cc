#include <bits/stdc++.h>
using namespace std;

// 台阶问题(给一个共有n阶的楼梯,每步可以走1/2步,求解决方法)
vector<int> choice{1, 2};
int res = 0;

void backtricking(vector<int> &choice, int cur, int n, int &res) {
    if (cur == n) {
        res++;
    }

    for (int i = 0; i < choice.size(); ++i) {
        if (cur + choice[i] > n)
            continue;
        backtricking(choice, cur + choice[i], n, res);
    }
}

int main() {
    int cur = 0;

    backtricking(choice, cur, 3, res);

    std::cout << res << std::endl;

    return 0;
}

void test() {
int a = 100;
int b = 200;


}