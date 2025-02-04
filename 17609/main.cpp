#include <bits/stdc++.h>
using namespace std;

/*
폰코딩임
*/

string s;

int check(int start, int end, bool used) {
  while (start < end) {
    if (s[start] != s[end]) {
      if (used) {
        if (check(start+1, end, false) == 0 || check(start, end-1, false) == 0) return 1;
      }
      return 2;
    }
    start++; end--;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  while(n--) {
    cin >> s;
    cout <<check(0, s.length() - 1, true) << '\n';
  }
}