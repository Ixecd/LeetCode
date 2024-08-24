#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算玩家的最终分数
     * @param text string字符串 一段文章text
     * @return int整型
     */
    
    int calculatingScore(string text) {
        // write code here
        string dis = "coder";
        int i = 0, ans = 0;
        while (i < text.size()) {
            string word;
            while (i < text.size() && isspace(text[i])) ++i;
            while (i < text.size() && !isspace(text[i])) {
                word += text[i++];
            }
            if (word.size() != dis.size()) continue;
            ++i;
            int j = 0;
            for (j = 0; j < dis.size(); ++j) {
                if (dis[j] == word[j] || dis[j] - 32 == word[j] || dis[j] == word[j] - 32);
                else break; 
            }
            if (j == dis.size()) ans++;

        }
        return ans;
    }
};
