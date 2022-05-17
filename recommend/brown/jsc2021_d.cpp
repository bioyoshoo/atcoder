#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int main() {
    ll N, P; cin >> N >> P;
    ll ans = (P - 1) * modpow(P - 2, N - 1, mod) % mod;
    cout << ans << endl;
}