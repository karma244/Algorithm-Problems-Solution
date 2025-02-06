#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dp[MAX][3], arr[MAX][3];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    cout << *min_element(dp[n], dp[n] + 3);
}