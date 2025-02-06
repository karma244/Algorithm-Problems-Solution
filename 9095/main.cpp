#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, p, dp[12];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int tc; cin >> tc;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4; //1,2 / 2,1 / 3 / 1,1,1
    while (tc--) {
        cin >> n;
        if (n < p) {
            cout << dp[n] << '\n';
            continue;
        }
        else {
            p = n;
            for (int i = 4; i <= n; i++) dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
            cout << dp[n] << '\n';
        }
    }
}