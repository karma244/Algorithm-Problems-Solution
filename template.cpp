#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO freopen("output","w",stdout); ios_base::sync_with_stdio(true); cin.tie(0);
using namespace std;
using LL = long long int;
using ULL = unsigned long long;

const double EPS =  1e-7;
const double PI  = acos(-1);

// DFS template
using myGraph = vector<vector<int>>;
vector<bool> visited;
void dfs(const myGraph &graph, int v) {
    visited[v] = true;

    for (auto next_v : graph[v]) {
        if (visited[next_v]) continue;

        dfs(graph, next_v);
    }
}

int binary_search(const vector<int>& v, int key) {
    int ng = -1;
    int ok = static_cast<int>(v.size());

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (v[mid] >= key) ok = mid;
        else ng = mid;
    }
    return ok;
}
int64_t gcd(int64_t a, int64_t b) {
    if (a < b) return gcd(b, a);

    int64_t r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

// power(x, n, mod) ::= (x ^ n) % mod
int64_t power(int64_t base, int64_t n, int64_t mod) {
    int64_t ret = 1;

    while (n > 0) {
        if (n & 1) {
            (ret *= base) %= mod;
        }
        (base *= base) %= mod;
        n >>= 1;
    }
    return ret;
}
bool is_prime(int64_t x) {
    for (int64_t i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
// 약수 열거
vector<int64_t> enumerate_divisors(int64_t n) {
    vector<int64_t> res;

    for (int64_t i = 1LL; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}
// 소인수분해
map<int64_t, int> prime_factor(int64_t n) {
    map<int64_t, int> ret;

    for (int64_t i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1) ret[n] = 1;
    return ret;
}