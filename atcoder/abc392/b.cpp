#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, m; cin >> n >> m;
    
    set<int> tmp;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        tmp.insert(x);
    }

    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (tmp.find(i) == tmp.end()) {
            ret.push_back(i);
        }
    }

    cout << ret.size() << endl;
    for (int num : ret) cout << num << ' ';
}