#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, dp[301], arr[301];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1], arr[2]) + arr[3];
    dp[4] = max(arr[1] + arr[3], dp[2]) + arr[4]; //특별한 경우로써, arr[1] = dp[1]이므로 성립한다.
    // 점화식 : dp[i] = max(arr[i-1] + dp[i-3], dp[i-2]) + arr[i]
    for (int i = 5; i <= n; i++)
        dp[i] = max(arr[i-1] + dp[i-3], dp[i-2]) + arr[i];
    cout << dp[n];
}