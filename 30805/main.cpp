#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<pii> a, b;

bool cmp(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back({x, i});
    };
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.push_back({x, i});
    };

    vector<int> ret;
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    int pta = 0, ptb = 0;
    for (int idxa = 0, idxb = 0; idxa < n && idxb < m;) {
        if (a[idxa].first == b[idxb].first) {
            if (pta > a[idxa].second) idxa++;
            else if (ptb > b[idxb].second) idxb++;
            else {
                pta = a[idxa].second;
                ptb = b[idxb].second;
                ret.push_back(a[idxa].first);
                idxa++, idxb++;
            }
        }
        else if (a[idxa].first > b[idxb].first) idxa++;
        else idxb++;
    }

    cout << (int)ret.size() << '\n';
    for (auto& x: ret) cout << x << ' ';
}