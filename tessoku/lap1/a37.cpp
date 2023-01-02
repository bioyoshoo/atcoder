#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M, B; cin >> N >> M >> B;
    vector<ll> A(N), C(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> C[i];

    ll ans = 0;
    rep(i, N) ans += M * A[i];
    ans += N * M * B;
    rep(i, M) ans += N * C[i];

    cout << ans << endl;
}