#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<ll> v;

bool go() {
    ll ratio = v[1] * v[1];
    for (size_t i = 1; i < v.size() - 1; i++) {
        if (v[i] * v[i] != v[i - 1] * v[i + 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.push_back(x);
    }
    go() ? cout << "Yes" : cout << "No";
}