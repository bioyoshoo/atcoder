#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<pair<ll, ll>> V(N);
    vector<ll> P(N);
    rep(i, N) {
        cin >> V[i].first >> V[i].second >> P[i];
    }

    vector<vector<ll>> T(N, vector<ll>(N));
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            ll d = abs(V[i].first - V[j].first) + abs(V[i].second - V[j].second);
            ll s = (d + P[i] - 1) / P[i];
            T[i][j] = s;
        }
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                T[i][j] = min(T[i][j], max(T[i][k], T[k][j]));
            }
        }
    }

    ll ans = 1e18;
    rep(i, N) {
        ll cand = 0;
        rep(j, N) cand = max(cand, T[i][j]);
        ans = min(ans, cand);
    }
    cout << ans << endl;
}