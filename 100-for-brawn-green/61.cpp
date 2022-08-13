#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, M; cin >> N >> M;

    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    rep(v, N) dp[v][v] = 0;
    rep(i, M) {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        a--; b--;
        dp[a][b] = t;
        dp[b][a] = t;
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    ll ans = INF;
    rep(i, N) {
        ll cand = 0;
        rep(j, N) cand = max(cand, dp[i][j]);
        ans = min(ans, cand);
    }
    cout << ans << endl;
}