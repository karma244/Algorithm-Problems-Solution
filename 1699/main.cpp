#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dp[100001] = { 0, 1, 2, 3, 1 };

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;

    for (int i = 5; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    cout << dp[n];
}