#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> X(N); rep(i, N) cin >> X[i];

    ll ans = 1e18;
    rep(i, N) {
        if (i + K - 1 >= N) continue;
        ll dist = X[i + K - 1] - X[i] + min(abs(X[i]), abs(X[i + K - 1]));
        ans = min(ans, dist);
    }
    cout << ans << endl;
}