/*아니 double도 터지는 것 같아서 어쩔 수없이 그냥 long long씀*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sx, sy, sxx, sxy;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    cout << fixed; cout.precision(9);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        sx += x;
        sy += y;
        sxx += x * x;
        sxy += x * y;
    }

    ll p = n * sxx - sx * sx;

    if (p == 0) {
        cout << "EZPZ\n";
    }
    else {
        double a2 = (double)(n * sxy - sx * sy) / p;
        double b2 = (sy - a2 * sx) / n;

        cout << a2 << ' ' << b2;
    }
}