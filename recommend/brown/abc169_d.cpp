#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a == 0) {
            ll exp = 0;
            while (n % a == 0) {
                exp++;
                n /= a;
            }
            res.push_back({a, exp});
        }
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() {
    ll N;
    cin >> N;

    vector<pair<ll, ll>> res = prime_factorize(N);
    ll ans = 0;
    for (auto p: res) {
        ll exp = p.second;
        ll t = 1, sum = 1;
        while (exp >= sum) {
            t += 1;
            sum += t;
        }
        ans += t - 1;
    }
    cout << ans << endl;
}