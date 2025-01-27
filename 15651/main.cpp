#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
int arr[8];
bool vis[8];

void go(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[cnt] = i;
        go(cnt + 1);
    } 
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n >> m;
    go(0);
}