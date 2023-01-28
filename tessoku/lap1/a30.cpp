#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll C(ll n, ll r) {
    ll X = 1, Y = 1;
    for (int x = n; x >= n - r + 1; x--) {
        X *= x; X %= mod;
    }
    for (int y = r; y >= 1; y--) {
        Y *= y; Y %= mod;
    }
    return X * modpow(Y, mod - 2) % mod;
}

int main() {
    ll n, r; cin >> n >> r;

    cout << C(n, r) << endl;
}