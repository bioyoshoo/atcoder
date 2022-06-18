#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll comb(ll n, ll k, ll mod) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    ll x = 1, y = 1;
    for (ll m = n - k + 1; m <= n; m++) x = x * m % mod;
    for (ll m = 1; m <= k; m++) y = y * m % mod;
    return x * modpow(y, mod - 2, mod) % mod;
}

int main() {
    int X, Y; cin >> X >> Y;

    ll ans = 0;
    if ((2*Y - X) % 3 == 0 && (2*X - Y) % 3 == 0) {
        ll a = (2*Y - X) / 3, b = (2*X - Y) / 3;
        if (a >= 0 && b >= 0) {
            ans = comb(a + b, a, mod);
        }
    }
    cout << ans << endl;
}