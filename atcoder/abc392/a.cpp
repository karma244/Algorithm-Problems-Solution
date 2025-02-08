#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, arr + 3);
    cout << (arr[0] * arr[1] == arr[2] ? "Yes" : "No");
}