#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int64_t modpow(int64_t a, int64_t n, int64_t mod) {
    int64_t res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int64_t comb(int64_t n, int64_t k, int64_t mod) {
    int64_t X = 1, Y = 1;
    for (int a = n - k + 1; a <= n; a++) X = X * a % mod;
    for (int a = 1; a <= k; a++) Y = Y * a % mod;

    return X * modpow(Y, mod - 2, mod) % mod;
}

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;

    int64_t ans = modpow(2, n, mod) - 1;
    ans -= (comb(n, a, mod) + comb(n, b, mod)) % mod;
    ans += 10 * mod;
    ans %= mod;
    cout << ans << endl;
}