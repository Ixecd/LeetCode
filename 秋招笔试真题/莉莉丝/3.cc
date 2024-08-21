#include <bits/stdc++.h>
using namespace std;

bool Solution(string &s1, string &s2) {
    int n1 = s1.size(), n2 = s2.size();
    unordered_map<char, int> umap;
    for (int i = 0; i < n2; ++i) {
        umap[s2[i]]++;
    }
    for (int i = 0; i < n1; ++i) {
        if (umap.count(s1[i])) 
            umap[s1[i]]--;
    }
    
    for (auto &[x, y] : umap) 
        if (y > 0) return false;
    
    return true;
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;
    bool ret = Solution(s1, s2);
    if (ret) 
        cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")