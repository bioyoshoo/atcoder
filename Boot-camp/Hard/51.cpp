#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int64_t modcomb(int64_t n, int64_t k, int64_t mod) {
    int64_t num = 1, deno = 1;
    for (int64_t i = n - k + 1; i <= n; i++) num = num * i % mod;
    for (int64_t i = 1; i <= k; i++) deno = deno * i % mod;
    // k!の逆元計算 k!の逆元 = (k!)^(mod - 2) (modは素数) に対応している
    int64_t inv = 1, pow = mod - 2;
    while (pow > 0) {
        if (pow & 1) inv = inv * deno % mod;
        deno = deno * deno % mod;
        pow >>= 1;
    }
    return num * inv % mod;
}

int main() {
    int64_t x, y;
    cin >> x >> y;

    int64_t a, b;
    if (((2 * y - x) % 3 == 0) && ((2 * x - y) % 3 == 0)) {
        a = (2 * y - x) / 3, b = (2 * x - y) / 3;
        if (a < 0 || b < 0) cout << 0 << endl;
        else cout << modcomb(a + b, a, mod) << endl;
    }
    else cout << 0 << endl;
}