#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int start = 0, end = n-1, diff = INT_MAX, ret[2];
    while (start < end) {
        if (abs(arr[start] + arr[end]) < diff) {
            ret[0] = arr[start];
            ret[1] = arr[end];
            diff = abs(arr[start] + arr[end]);
        }
        if (arr[start] + arr[end] < 0) start++;
        else end--;
    }

    sort(ret, ret + 2);
    for (auto x:ret) cout << x << ' ';
}