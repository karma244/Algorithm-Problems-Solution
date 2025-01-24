#include <bits/stdc++.h>
using namespace std;

int graph[51][51];
int vis[51][51];
int w, h; 
int dx[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dy[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

void dfs(int y, int x) {
    vis[y][x] = true;
 
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (0 <= nx && 0 <= ny && nx < 50 && ny < 50) {
            if (graph[ny][nx] && !vis[ny][nx]) {
                vis[ny][nx] = true;
                dfs(ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);

    while(1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++) 
                cin >> graph[i][j];

        int ret = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j] && !vis[i][j]) {
                    ret++;
                    dfs(i, j);
                }
            }
        }
        cout << ret << '\n';
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
        ret = 0;
    }

    return 0;
}