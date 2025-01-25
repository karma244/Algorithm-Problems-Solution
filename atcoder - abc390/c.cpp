#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<string> grid;

bool isRectanglePossible(int h, int w) {
    int top = h, bottom = -1, left = w, right = -1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (grid[i][j] == '.') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int h, w; cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    isRectanglePossible(h, w) ? cout << "Yes" : cout << "No";
}