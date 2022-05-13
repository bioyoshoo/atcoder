#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> factorize(ll n) {
    vector<ll> res;
    for (ll a = 1; a * a <= n; a++) {
        if (n % a == 0) {
            res.push_back(a);
            if (a != n / a) res.push_back(n / a);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N;
    cin >> N;

    vector<ll> V = factorize(2*N);
    ll ans = 0;
    for (ll x: V) {
        ll y = 2 * N / x;
        if ((y - x + 1) > 0 && (y - x + 1) % 2 == 0) ans += 2;
    }
    cout << ans << endl;
}