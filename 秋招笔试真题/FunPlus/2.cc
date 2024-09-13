#include <bits/stdc++.h>
using ll = long long;
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断给定的扑克牌通否通过排列和四则运算得到指定的值
     * @param cards int整型vector 扑克牌对应的数字
     * @param points int整型 扑克牌需要通过排列和四则运算得到的值
     * @return bool布尔型
     */
    bool is_first = true;
    bool res = false;
    // 0 -> -
    // 1 -> +
    // 2 -> *
    // 3 -> /
    double operation(int curSum, int j, int card) {
        switch (j) {
            case 0 : 
                return curSum - card;
            case 1 :
                return curSum + card;
            case 2 : 
                return curSum * card;
            case 3 : 
                return curSum / card;
            default:
                return -1;
        }
    }
    void dfs(vector<int>& cards, vector<bool>& used, int points, double curSum) {
        if (curSum == points) {
            res = true;
            return;
        } 
        for (int i = 0; i < cards.size(); ++i) {
            if (used[i]) continue;
            if (is_first) {
                is_first = false;
                used[i] = true;
                dfs(cards, used,  points, curSum + cards[i]);
                used[i] = false;
            } else {
                for (int j = 0; j < 4; ++j) {
                    used[i] = true;
                    dfs(cards, used, points, operation(curSum, j, cards[i]));
                    used[i] = false;
                }
            }
        }
    }
    bool judgePoints(vector<int>& cards, int points) {
        vector<bool> used(cards.size(),  false);
        dfs(cards, used, points, 0);
        return res;
    }
};