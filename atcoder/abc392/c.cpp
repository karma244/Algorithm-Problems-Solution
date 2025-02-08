#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;

    vector<int> P(n + 1), Q(n + 1), tmp(n + 1);

    for (int i = 1; i <= n; i++) cin >> P[i];

    for (int i = 1; i <= n; i++) cin >> Q[i], tmp[Q[i]] = i;

    for (int i = 1; i <= n; i++) {
        int stared_person = P[tmp[i]]; 
        cout << Q[stared_person] << " "; 
    }
}
