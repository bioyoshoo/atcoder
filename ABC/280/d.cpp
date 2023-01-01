#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

vector<pair<ll, ll>> factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        ll ex = 0;
        while (n % a == 0) {
            ex++; n /= a;
        }
        res.push_back({a, ex});
    }
    if (n > 1) res.push_back({n, 1});
    
    return res;
}

ll rec(ll k) {

    vector<pair<ll, ll>> res = factorize(k);

    if (res.size() == 1) return res[0].first;

    ll ans = 1;
    for (auto p: res) {
        ll a = p.first, r = p.second;

        ll n = 1;
        rep(i, r) n *= a;

        ans = max(ans, rec(n));
    }
    return ans;
}

int main() {
    ll K; cin >> K;

    cout << rec(K) << endl;
}
