#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dp[41][2] = {{1, 0}, {0, 1}, {1, 1}, {1, 2}};

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 4; i <= n; i++) 
            for (int j = 0; j < 2; j++) 
                dp[i][j] = dp[i-1][j] + dp[i-2][j];
        
        for (int i = 0; i < 2; i++)
            cout << dp[n][i] << ' ';
        cout << '\n';
    }
}