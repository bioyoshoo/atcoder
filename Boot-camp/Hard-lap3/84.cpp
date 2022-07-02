#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    rep(i, N) rep(j, 10) cin >> F[i][j];
    vector<vector<int>> P(N, vector<int>(11));
    rep(i, N) rep(j, 11) cin >> P[i][j];

    ll ans = -1e10;
    for (ll i = 1; i < (1LL << 10); i++) {
        vector<int> Q(N);
        rep(j, 10) {
            if (i & (1LL << j)) {
                rep(k, N) Q[k] += F[k][j];
            }
        }
        ll cand = 0;
        rep(j, N) cand += P[j][Q[j]];
        ans = max(ans, cand);
    }
    cout << ans << endl;
}