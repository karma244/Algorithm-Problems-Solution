#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
O(M-N)이라 테케 좀 추가되면 터질 것 같지만, 일단 AC 받음...
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    unordered_set<int> used;
    vector<int> result;
    
    for (int i = 1; i <= M; ++i) {
        if (used.count(i ^ K)) {
            continue;
        }

        result.push_back(i);
        used.insert(i);

        if (result.size() == N) break;
    }

    if (result.size() == N) {
        for (int x : result) cout << x << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}