#include <bits/stdc++.h>
using namespace std;

int graph[50][50];
int dx[4] = { 0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1};

int m, n, k;

void dfs(int x, int y) {
    graph[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < m && nx >= 0 && ny >= 0 && ny < n) {
            if (graph[nx][ny] == 1) dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int ret = 0; cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            graph[x][y] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << '\n';
        ret = 0;
        memset(graph, 0, sizeof(graph));
    }
}