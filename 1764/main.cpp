#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<string> never;
int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        never.push_back(s);
    }
    sort(never.begin(), never.end());
    vector<string> nvrever;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (binary_search(never.begin(), never.end(), s))
            nvrever.push_back(s);
    }
    sort(nvrever.begin(), nvrever.end());
    cout << (int)nvrever.size() << '\n';
    for (auto& x: nvrever) cout << x << '\n';
}