#include <bits/stdc++.h>
using ll = long long;
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param res int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int prize(vector<int>& res, int target) {
        // write code here
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] >= target) return i + 1;
        }
        return -1;
    }
};