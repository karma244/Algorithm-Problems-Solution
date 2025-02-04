#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int N) {
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int N;
    cin >> N;

    vector<int> primes = sieveOfEratosthenes(N);

    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}