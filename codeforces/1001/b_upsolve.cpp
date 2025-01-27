#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        bool flag = false;
        int v[n];
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) {
            if (v[i] <= max(2*i, 2*(n-1-i))) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "NO\n" : "YES\n");
    }

    return 0;
}