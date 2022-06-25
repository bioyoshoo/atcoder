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

ll modcomb(ll n, ll a, ll mod) {
    ll x = 1, y = 1;
    for (int i = n - a + 1; i <= n; i++) x = x * i % mod;
    for (int i = 1; i <= a; i++) y = y * i % mod;
    return x * modpow(y, mod - 2, mod) % mod;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;

    mint ans = modpow(2, n, mod) - (1 + modcomb(n, a, mod) + modcomb(n, b, mod));
    cout << ans.val() << endl;
}