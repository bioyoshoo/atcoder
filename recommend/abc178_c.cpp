#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long N;
    cin >> N;

    long long complement = 2 * modpow(9, N, mod) % mod - modpow(8, N, mod);
    if (complement < 0) complement += mod;
    long long ans = modpow(10, N, mod) - complement;
    if (ans < 0) ans += mod;
    cout << ans << endl;
}