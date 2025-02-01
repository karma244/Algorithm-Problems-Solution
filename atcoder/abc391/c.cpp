#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> nests;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int N, Q; cin >> N >> Q;

    vector<int> a(N + 1); 
    vector<int> b(N + 1, 1);
    int tmp = 0;

    for (int i = 1; i <= N; i++) a[i] = i;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) { 
            int P, H; cin >> P >> H;

            int pa = a[P];

            if (--b[pa] == 1) tmp--; 

            a[P] = H;
            if (++b[H] == 2) tmp++; 

        } else  cout << tmp << endl;
    }
}