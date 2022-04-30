#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int64_t modpow(int64_t a, int64_t n, int64_t mod) {
    int64_t res = 1;
    while (n > 0) {
        if (1 & n) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int64_t Comb(int64_t n, int64_t k, int64_t mod) {
    int64_t X = 1, Y = 1;
    for (int64_t a = n - k + 1; a <= n; a++) X = X * a % mod;
    for (int64_t a = 1; a <= k; a++) Y = Y * a % mod;
    return X * modpow(Y, mod - 2, mod) % mod;
}

int main() {
    int64_t x, y;
    cin >> x >> y;

    int64_t ans = 0;
    if ((2 * x - y) % 3 == 0 && (2 * y - x) % 3 == 0) {
        int64_t a = (2 * x - y) / 3, b = (2 * y - x) / 3;
        if (a >= 0 && b >= 0) ans = Comb(a + b, a, mod);
    }

    cout << ans << endl;
}