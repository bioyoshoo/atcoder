#include <bits/stdc++.h>
using namespace std;
using p = vector<pair<int64_t, int64_t>>;
const int64_t mod = 1e9 + 7;

p prime_factorize(int64_t n) {
    p ans;
    for (int a = 2; a * a <= n; a++) {
        int64_t exp = 0;
        while (n % a == 0) {
            exp++;
            n /= a;
        }
        ans.push_back({a, exp});
    }
    if (n > 1) ans.push_back({n, 1});
    return ans;
}

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> primes(1001, 0);
    for (int n = 2; n <= N; n++) {
        p n_factorize = prime_factorize(n);
        for (auto f: n_factorize) primes.at(f.first) += f.second;
    }

    int64_t ans = 1;
    for (int64_t i: primes) {
        ans *= (i + 1);
        ans %= mod;
    }

    cout << ans << endl;
}