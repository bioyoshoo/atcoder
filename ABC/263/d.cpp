#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, L, R; cin >> N >> L >> R;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll sum = 0;
    rep(i, N) sum += A[i];

    vector<ll> lmerit(N);
    ll sum1 = 0;
    ll sum2 = 0;

    rep(i, N) {
        sum1 += A[i];
        sum2 += L;
        lmerit[i] = sum1 - sum2;
    }

    vector<ll> rmerit(N);
    sum1 = 0; sum2 = 0;
    for (int i = N - 1; i >= 0; i--) {
        sum1 += A[i];
        sum2 += R;
        rmerit[i] = sum1 - sum2;
    }

    vector<ll> lmax(N + 1), rmax(N + 1);
    lmax[0] = 0;
    ll v = 0;
    for (int i = 1; i < N + 1; i++) {
        v = max(v, lmerit[i - 1]);
        lmax[i] = v;
    }

    rmax[N] = 0;
    v = 0;
    for (int i = N - 1; i >= 0; i--) {
        v = max(v, rmerit[i]);
        rmax[i] = v;
    }

    ll ans = 1e18;
    for (int i = 0; i < N + 1; i++) {
        ans = min(ans, sum - lmax[i] - rmax[i]);
    }
    cout << ans << endl;
}