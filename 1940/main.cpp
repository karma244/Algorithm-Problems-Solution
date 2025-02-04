#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int start = 0, end = n-1, ret = 0;
    while (start < end) {
        if (arr[start] + arr[end] == m) {
            ret++;
            start++;
            end--;
        }
        else if (arr[start] + arr[end] > m) end--;
        else start++;
    }
    cout << ret;  
}