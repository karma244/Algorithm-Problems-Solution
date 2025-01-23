#include <bits/stdc++.h>
using namespace std;

struct Block {
    int id;
    int parent_id;
    int transaction;
};

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int n; cin >> n;

    vector<Block> blocks(n);
    for (int i = 0; i < n; i++)
        cin >> blocks[i].id >> blocks[i].parent_id >> blocks[i].transaction;

    int balance = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 && blocks[i].parent_id != 0) {
            cout << "INVALID" << '\n';
            return 0;
        }

        if (i > 0 && blocks[i].parent_id != blocks[i - 1].id) {
            cout << "INVALID" << '\n';
            return 0;
        }

        balance += blocks[i].transaction;

        if (balance < 0) {
            cout << "NO_MONEY" << '\n';
            return 0;
        }
    }

    cout << balance << '\n';
    return 0;
}
