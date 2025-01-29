#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

map<string, string> info;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, m; cin >> n >> m;

    while(n--) {
        string s, p; cin >> s >> p;
        info.insert({s, p});
    }
    
    while(m--) {
        string c; cin >> c;
        cout << info[c] << '\n';
    }
}