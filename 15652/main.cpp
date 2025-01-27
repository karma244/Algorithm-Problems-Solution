#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
int arr[8];

void go(int num, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++) {
        arr[k] = i;
        go(i, k + 1);
    } 
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n >> m;
    go(1,0);
}