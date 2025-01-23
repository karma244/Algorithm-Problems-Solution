#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int a, b, c; cin >> a >> b >> c;

    string s = to_string(a*b*c);
    for (int i = 0; i < s.length(); i++) 
        arr[s[i] - '0'] ++;
    
    for (int &x : arr) cout << x << '\n';
}