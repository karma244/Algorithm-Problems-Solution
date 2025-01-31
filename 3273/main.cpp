#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, x; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    sort(arr.begin(), arr.end());
    int start = 0, end = n-1, sum = 0;
    while (start < end) {
        if (arr[start] + arr[end] == x) {
            sum++;
            start++;
            end--;
        }
        else if (arr[start] + arr[end] > x) {
            end--;
        }
        else start++;
    }
    cout << sum;
}