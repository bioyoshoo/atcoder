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
    ll N, M; cin >> N >> M;

    vector<ll> res = factorize(M);
    reverse(res.begin(), res.end());
    ll ans;
    for (auto r: res) {
        if (r * N <= M) {
            ans = r;
            break;
        }
    }
    cout << ans << endl;
}