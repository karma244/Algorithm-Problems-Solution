#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string grid[601];
bool vis[601][601];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = {-1, 1, 0, 0 };
int n, m, ret;

void dfs(int x, int y) {
    if (grid[x][y] == 'P') ret++;
    vis[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (!vis[nx][ny] && grid[nx][ny] != 'X') {
                vis[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);

    int x, y; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'I') x = i, y = j;

    dfs(x, y);
    ret == 0 ? cout << "TT" : cout << ret; 
}