#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dp[100001] = {1, 3, 7, 17};

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    for (int i = 4; i <= n; i++) dp[i] = (dp[i-1] * 2 + dp[i-2]) % 9901;

    cout << dp[n];
}