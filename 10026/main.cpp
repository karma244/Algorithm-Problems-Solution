#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string graph[101];
bool vis[101][101];
string chkN = "RGB";
int n;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0};

void dfs(int x, int y, char chk) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < 100 && ny < 100) {
            if (!vis[nx][ny] && graph[nx][ny] == chk) {
                vis[nx][ny] = true;
                dfs(nx, ny, chk);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> graph[i];
    
    int normal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto& x: chkN) {
                if (!vis[i][j] && graph[i][j] == x) {
                    normal++;
                    dfs(i, j, x);
                }
            }
        }
    }
    cout << normal << ' ';
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (graph[i][j] == 'G') graph[i][j] = 'R';

    int stranger = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto& x: "RB") {
                if (!vis[i][j] && graph[i][j] == x) {
                    stranger++;
                    dfs(i, j, x);
                }
            }
        }
    }
    cout << stranger;
}