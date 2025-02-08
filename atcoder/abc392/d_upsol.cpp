#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
else 조건 때문인 듯.
하......
*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dice(n);
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int a; cin >> a;
            dice[i].push_back(a);
        }
        sort(dice[i].begin(), dice[i].end());
    }
    double ret = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            const auto& A = dice[i];
            const auto& B = dice[j];
            double count = 0;
            int cntA = 0, cntB = 0;

            while(cntA < A.size() && cntB < B.size()){
                if(dice[i][cntA]==dice[j][cntB]){
                    double a=0, b=0;
                    while(dice[i][cntA] ==  dice[j][cntB] && cntA < A.size()) {
                        cntA++;
                        a++;
                    }
                    while(dice[i][cntA-1] == dice[j][cntB] && cntB < B.size()) {
                        cntB++;
                        b++;
                    }
                    count += a*b;
                }
                else {
                    if(dice[i][cntA] < dice[j][cntB])
                        cntA++;
                    else
                        cntB++;
                }
            }
            count = count / (dice[i].size()*dice[j].size());
            ret = max(ret, count);
        }
    }

    cout << fixed << setprecision(13) << ret;
}