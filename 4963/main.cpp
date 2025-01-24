#include <bits/stdc++.h>
#define IO freopen("output","w",stdout); ios_base::sync_with_stdio(true); cin.tie(0);
using namespace std;

int graph[51][51];
int vis[51][51];
int w, h; 
int dx[8] = { 0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = { -1, 1, 0, 0 , 1, -1, -1, 1};

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
            if (!vis[nx][ny] && graph[nx][ny] == 1) {
                vis[nx][ny] = 1;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    IO;

    while(1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++) 
                cin >> graph[i][j];

        int ret = 0;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (!vis[i][j] && graph[i][j] == 1) { 
                    vis[i][j] = 1;
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}