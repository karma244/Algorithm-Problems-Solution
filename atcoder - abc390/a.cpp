#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_sorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++) { 
        vector<int> B = A;
        swap(B[i], B[i + 1]);
        if (is_sorted(B)) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}
