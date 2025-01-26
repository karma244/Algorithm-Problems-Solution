#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
int arr[10];
bool vis[10];

void go(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            arr[k] = i;
            vis[i] = true;
            go(k + 1);
            vis[i] = false;
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n >> m;
    go(0);
}