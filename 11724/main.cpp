#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int graph[MAX][MAX];
bool vis[MAX];
int n, m;

void dfs(int v) {
    vis[v] = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && graph[v][i] == 1) {
            vis[i] = false;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n >> m;
    for (int  i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ret++;
            dfs(i);
        }
    }
    cout << ret;
}