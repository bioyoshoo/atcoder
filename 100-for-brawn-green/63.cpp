#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        ll exp = 0;
        while (n % a == 0) {
            exp++;
            n /= a;
        }
        res.push_back({a, exp});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() {
    ll n; cin >> n;
    vector<pair<ll, ll>> res = prime_factorize(n);

    cout << n << ":";
    for (auto r: res) {
        ll exp = r.second;
        rep(i, exp) cout << " " << r.first;
    }
    cout << endl;
}