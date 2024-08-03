#include <bits/stdc++.h>
using namespace std;

vector<int> Father;

void make_set(int x) {
    Father[x] = 0;
}

int find(int x) {
    if (Father[x] <= 0) return x;
    Father[x] = find(Father[x]);
    return Father[x];
}

void Union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (Father[fx] < Father[fy]) {
        Father[fy] = fx;
    } else {
        Father[fx] = fy;
        if (Father[fx] == Father[fy]) Father[fy]--;
    }
}

int Solution1() {

    vector<int> ary{1,2,3,4,5,6,7,8};
    Father.resize(ary.size() + 1);
    for (int num : ary) 
        make_set(num);
    
    int times = 0;
    cin >> times;
    int x, y;
    while (times--) {
        cin >> x >> y;
        Union(x, y);
    }
    std::cout << "union OK" << std::endl;
    int qus;
    cin >> qus;
    while (qus--) {
        cin >> x >> y;
        if (find(x) == find(y)) 
            std::cout << x << " and " << y << " equal" << std::endl;
        else {
            std::cout << find(x) << " " <<find(y) << std::endl;
        }
    }

    return 0;
}

int Solution2() {
    int n = 10;
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) make_set(i);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            if (i == j) continue;
            else if (c[i][j] == 1) Union(i, j);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (find(i) == i) cnt++;
    }
    return cnt;
}

//ACM/ICPC
//操场上有n个同学,自成一列.每次操作老师指令是"x,y", x 排到 y 的后面, 最后每个同学的队列队首
vector<int> father;
void MS(int x) {
    father[x] = 0;
}
int FIND(int x) {
    if (father[x] == 0) return x;
    father[x] = FIND(father[x]);
    return father[x];
}
void UNION(int x, int y) {
    int fx = FIND(x), fy = FIND(y);
    // if (fx == fy) return;
    father[fx] = fy;
}
int Solution3() {
    int n = 10;
    father.resize(n);
    for (int i = 0; i < n; ++i) MS(i);
    int times;
    cin >> times;
    int x, y;
    while (times--) {
        cin >> x >> y;
        UNION(x, y);
    }
    for (int i = 0; i < n; ++i) 
        std::cout << FIND(i) << " ";
    return 0 ;
}