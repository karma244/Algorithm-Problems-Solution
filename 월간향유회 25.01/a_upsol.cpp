#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
고수분의 조언을 받았다. (Without set)
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> result;
    for (int i = 1; i <= M && result.size() < N; i++) {
        if ((K != i) && ((K^i) < i)) continue;
        result.push_back(i);
    }

    if (result.size() == N) for(int x: result) cout << x << ' ';
    else cout << -1;

    return 0;
}