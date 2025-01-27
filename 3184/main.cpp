#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
'#'이 울타리이므로 울타리 안에서 양과 늑대의 수를 비교하여 
양의 수가 늑대의 수보다 많다면 전체 양의 수에 울타리 안에 있는 양의 수를 더해주고
아니라면 전체 늑대의 수에 울타리 안에 있는 늑대의 수를 더해준다. 
그리고 울타리 안에 있는 늑대와 양의 수를 0으로 바꾼다.
*/

string grid[251];
bool vis[251][251];
int r, c, sheep, wolf, t_sheep, t_wolf; 
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    vis[x][y] = true;
    
    if (grid[x][y] == 'v') wolf++;
    else if (grid[x][y] == 'o') sheep++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
            if (!vis[nx][ny] && grid[nx][ny] != '#') { //vis[nx][ny] != '#' (?)
                dfs(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> grid[i];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j]) {
                dfs(i, j);
                if (sheep > wolf) t_sheep += sheep;
                else t_wolf += wolf;
                wolf = sheep = 0;
            }
        }
    }

    cout << t_sheep << ' ' << t_wolf;
}