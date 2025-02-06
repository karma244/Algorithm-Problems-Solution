#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll dp[101];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int tc, n, p = 0; cin >> tc;
    while (tc--) {
        cin >> n;
        dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
        dp[6] = 3, dp[7] = 4, dp[8] = 5, dp[9] = 7, dp[10] = 9;
        if (n < p || n < 11) {
            cout << dp[n] << '\n';
            continue;
        }
        else {
            p = n;
            for (int i = 11; i <= n; i++) dp[i] = dp[i-2] + dp[i-3];
            cout << dp[n] << '\n';
        }
    }
}