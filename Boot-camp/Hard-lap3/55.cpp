#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, A, B; cin >> N >> A >> B;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];
    ll ans = 0;
    rep(i, N - 1) {
        if (A * (X[i + 1] - X[i]) < B) ans += A * (X[i + 1] - X[i]);
        else ans += B;
    }
    cout << ans << endl;
}