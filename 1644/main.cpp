#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> arr;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<bool> tmp(n+1, true);

    tmp[0] = tmp[1] = false;

    for (int i = 2; i * i <= n; i++) 
        if (tmp[i]) for (int j = i * i; j <= n; j += i) tmp[j] = false;

    for (int i = 2; i <= n; i++) 
        if (tmp[i]) arr.push_back(i);

    int start = 0, end = 0, sum = arr[0], ret = 0;
    while (start <= end && end < arr.size()) {
        if (sum == n) ret++;
        if (sum < n) end++, sum += arr[end];
        else sum -= arr[start], start++;
    }
    cout << ret;
}