#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int grid[501][501], res, n, m;
bool vis[501][501];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
 
void dfs(int x, int y, int d, int sum) {
	sum += grid[x][y];
	vis[x][y] = true;
	if (d == 4) {
		res = max(res, sum);
		vis[x][y] = false;
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (!vis[nx][ny])
				dfs(nx, ny, d + 1, sum);
		}
	}
	vis[x][y] = false;
}

void go(int x, int y) {
	int sum;
	for (int i = 0; i < 4; i++) {
		sum = grid[x][y];
		for (int dir = 0; dir < 4; dir++) {
			if (dir == i)
				continue;
			int nx = x + dy[dir];
			int ny = y + dx[dir];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				sum += grid[nx][ny];
		}
		res = max(res, sum);
	}
}
                
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int i, j; cin >> n >> m;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> grid[i][j];
 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			dfs(i, j, 1, 0);
            go(i, j);
		}
	}
    cout << res;
}
