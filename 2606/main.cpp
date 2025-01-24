#include <bits/stdc++.h>
using namespace std;

int graph[101][101];
bool vis[101];
int n, m, ret;

void dfs(int v) {
    vis[v] = true;

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && graph[v][i] == 1) {
            ret ++;
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    dfs(1);

    cout << ret;
}