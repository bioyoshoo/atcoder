#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll ans = 1e18;
    rep(i, N) {
        rep(j, N) {
            ll s = A[i], t = B[j];

            ll cand = 0;
            rep(k, N) {
                ll dist1 = abs(s - A[k]) + abs(A[k] - B[k]) + abs(B[k] - t);
                ll dist2 = abs(s - B[k]) + abs(A[k] - B[k]) + abs(A[k] - t);
                cand += min(dist1, dist2);
            }
            ans = min(ans, cand);
        }
    }
    cout << ans << endl;
}