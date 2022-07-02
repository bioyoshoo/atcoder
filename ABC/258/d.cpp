#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, X; cin >> N >> X;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    
    vector<ll> C(N);
    rep(i, N) C[i] = A[i] + B[i];
    for (int i = 1; i < N; i++) C[i] += C[i - 1];

    ll ans = 1e18;
    rep(i, N) {
        ll cnt = X;
        ll cand = C[i];
        cnt -= (i + 1);
        if (cnt < 0) continue;
        cand += B[i] * cnt;
        ans = min(cand, ans);
    }
    cout << ans << endl;
}