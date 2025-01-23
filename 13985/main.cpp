#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    string s; getline(cin, s);

    s[0] - '0' + s[4] - '0' == s[8] - '0' ? cout << "YES" : cout << "NO";
}