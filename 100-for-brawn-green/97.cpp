#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll a = 1;
    rep(i, N) a = lcm(a, A[i]);

    ll ans = (2*M / a + 1) / 2;

    rep(i, N) if ((a / A[i]) % 2 == 0) ans = 0;

    cout << ans << endl;
}