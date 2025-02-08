#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dice(n);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        dice[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> dice[i][j];
        }
        sort(dice[i].begin(), dice[i].end());
    }

    double max_prob = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            const auto& A = dice[i];
            const auto& B = dice[j];
            double count = 0, total = A.size() * B.size();

            int start = 0, end = 0;
            while (start < A.size() && end < B.size()) {
                if (A[start] == B[end]) {
                    int val = A[start];
                    int cntA = 0, cntB = 0;
                    while (start < A.size() && A[start] == B[end]) {
                        cntA++;
                        start++;
                    }
                    while (end < B.size() && A[start-1] == B[end]) {
                        cntB++;
                        end++;
                    }
                    count += (cntA * cntB);
                } 
                else if (A[start] < B[end])
                    start++;
                else
                    end++;
            }

            double prob = count / total;
            max_prob = max(max_prob, prob);
        }
    }

    cout << fixed << setprecision(13) << max_prob << endl;
}