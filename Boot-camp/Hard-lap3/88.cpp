#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll f(ll n) {
    ll res = 0;
    rep(i, 50) {
        ll m = (1LL << (i + 1));
        ll loop = (n + 1) / m;
        ll residual = (n + 1) % m;
        ll one = loop * (m / 2) + max(0LL, residual - m / 2);
        if (one % 2 == 1) res += (1LL << i);
    }
    return res;
}

int main() {
    ll A, B; cin >> A >> B;
    ll ans = f(A - 1) ^ f(B);
    cout << ans << endl;
}
