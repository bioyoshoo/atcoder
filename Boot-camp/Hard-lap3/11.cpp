#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        ll exp = 0;
        while (n % a == 0) {
            n /= a;
            exp++;
        }
        res.push_back({a, exp});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() {
    ll A, B; cin >> A >> B;
    ll C = gcd(A, B);

    ll ans = 1;
    vector<pair<ll, ll>> res = prime_factorize(C);
    ans += res.size();
    cout << ans << endl;
}