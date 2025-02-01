#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    string d; cin >> d;
    if (d == "N") cout << "S";
    else if (d == "S") cout << "N";
    else if (d == "E") cout << "W";
    else if (d == "W") cout << "E";
    else if (d == "NE") cout << "SW";
    else if (d == "SE") cout << "NW";
    else if (d == "NW") cout << "SE";
    else if (d == "SW") cout << "NE";

    return 0;
}