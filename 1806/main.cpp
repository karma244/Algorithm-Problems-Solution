#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, s; cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int start = 0, end = 0, sum = arr[0], ret = INT_MAX;
    while (start <= end && end < n) {
        if (sum >= s) ret = min(ret, end-start + 1);
        if (sum < s) end++, sum += arr[end];
        else sum -= arr[start], start++;
    }
    cout << (ret == INT_MAX ? 0 : ret);
}