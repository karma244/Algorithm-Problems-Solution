#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr(n+1);
    vector<int> dp(k+1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) 
        for (int j = arr[i]; j <= k; j++)
            dp[j] += dp[j-arr[i]];

    cout << dp[k];
}