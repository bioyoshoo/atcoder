#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 1e9 + 7;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modcomb(ll n, ll k) {
    if (n < k) return 0;
    ll X = 1, Y = 1;
    for (ll x = n; x >= n - k + 1; x--) X = X*x % mod;
    for (ll y = k; y >= 1; y--) Y = Y*y % mod;
    return X * modpow(Y, mod - 2) % mod;
}

int main() {
    ll X, Y; cin >> X >> Y;
    
    ll ans = 0;
    if ((2*Y - X) % 3 == 0 && (2*X - Y) % 3 == 0) {
        ll a = (2*Y - X) / 3, b = (2*X - Y) / 3;
        if (a >= 0 && b >= 0) {
            ans = modcomb(a + b, a);
        }
    }
    cout << ans << endl;
}