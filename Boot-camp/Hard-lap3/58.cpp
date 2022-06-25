#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<ll> factorize(ll n) {
    vector<ll> res;
    for (ll a = 1; a * a <= n; a++) {
        if (n % a != 0) continue;
        res.push_back(a);
        if (n / a != a) res.push_back(n / a);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N; cin >> N;
    vector<ll> res = factorize(N);
    ll ans = 0;
    for (auto k: res) {
        ll m = N / k - 1;
        if (k < m) ans += m;
    }
    cout << ans << endl;
}