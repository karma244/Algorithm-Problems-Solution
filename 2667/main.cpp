#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string graph[26];
int n, house = 1;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool vis[26][26];
vector<int> v;

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < 26 && ny < 26) {
            if (!vis[nx][ny] && graph[nx][ny] == '1') {
                house++;
                vis[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}          

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> graph[i];
        
    int ret = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && graph[i][j] == '1') {
                dfs(i, j);
                v.push_back(house);
                house = 1;
                ret++;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << ret << '\n';
    for (auto& x : v) cout << x << '\n';
}