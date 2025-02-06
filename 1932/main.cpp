#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dp[501][501];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, ret = -1; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> dp[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) dp[i][j] += dp[i-1][1];
            else if (j == i) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret;
}