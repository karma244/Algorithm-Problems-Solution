#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        set<int> a, b;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.insert(x);
        }
        cout << (a.size() + b.size() < 4 ? "NO\n" : "YES\n");
    }
    return 0;
}