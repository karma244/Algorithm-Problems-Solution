#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(true); cin.tie(0);
    int N, M; cin >> N >> M;

    double ratio = (double)M / N;
    
    int totalMinutes = 24 * 60;
    int elapsedMinutes = ratio * totalMinutes;

    int hours = elapsedMinutes / 60;
    int minutes = elapsedMinutes % 60;

    cout << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes << endl;
}