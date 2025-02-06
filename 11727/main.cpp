#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dp[1001];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    for (int i = 5; i <= n; i++) dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    cout << dp[n];
}