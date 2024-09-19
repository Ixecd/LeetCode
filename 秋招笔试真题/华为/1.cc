#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> express;
    express.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        getline(cin, express[i]);
    }   
    unordered_map<string, string> umap;
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        umap[s1] = s2;
    }
    stack<int> v;
    stack<char> op;

    for (int i = 1; i <= n; ++i) {
        string str = express[i];
        string spice;
        string s_v;
        bool first = false;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == ' ') {
                continue;
            }
            if (str[j] == '=')  continue;
            else if (str[j] == 'A') {
                while (str[j] != 'D') ++j;
                while (!op.empty() && op.top() == '|') {
                    int first = v.top(); v.pop();
                    int second = v.top(); v.pop();
                    op.pop();
                    v.push(first | second);
                }
                op.push('&');
            } else if (str[j] == 'O') {
                while (str[j] != 'R') ++j;
                op.push('|');
            } else if (str[j] == '(') {
                op.push('(');
            } else if (str[j] == ')') {
                while (!op.empty() && !v.empty() && op.top() != '(') {
                    int first = v.top(); v.pop();
                    int second = v.top(); v.pop();
                    char p = op.top(); op.pop();
                    if (p == '|') {
                        v.push(first | second);
                    } else if (p == '&') {
                        v.push(first & second);
                    }
                }
                op.pop();
            } else if (str[j] == '\'' && first == false) {
                cout << "first" << endl;
                first = true;
            } else if (str[j] == '\'' && first == true) {
                cout << "second" << endl;
                if (s_v == umap[spice]) v.push(1);
                else v.push(0);
                cout << "push success" << endl;
                first = false;
                spice.clear();
                s_v.clear();
            } else if(first == false) {
                spice += str[j];
                cout << "spice = " << spice << endl;
            } else if (first == true) {
                s_v += str[j];
                cout << "s_v = " << s_v << endl;
            }
        }
        cout << "v.size() = " << v.size() << endl;
        cout << "op.size() = " << op.size() << endl;
        int res = v.top();
        if (res == 1) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}