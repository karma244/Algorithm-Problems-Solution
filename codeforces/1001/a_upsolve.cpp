#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ret = 0;
        for (auto& x: s) if (x == '1') ret++;
        cout << ret << endl;
    } 
}