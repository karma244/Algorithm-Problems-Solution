#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int N, M; cin >> N >> M;
    
    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<char>> T(M, vector<char>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> T[i][j];

    for (int a = 0; a <= N - M; a++) {
        for (int b = 0; b <= N - M; b++) {
            bool found = true;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (S[a + i][b + j] != T[i][j]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }
            if (found) {
                cout << (a + 1) << " " << (b + 1) << endl;
                return 0;
            }
        }
    }

    return 0;
}