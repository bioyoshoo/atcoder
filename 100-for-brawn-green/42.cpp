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
    vector<ll> D(N + 1), C(M + 1);
    rep(i, N) cin >> D[i + 1];
    rep(i, M) cin >> C[i + 1];

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            chmin(dp[i][j], dp[i][j - 1]);
            if (i > 0) chmin(dp[i][j], dp[i - 1][j - 1] + C[j] * D[i]);
        }
    }

    ll ans = INF;
    for (int i = 0; i <= M; i++) chmin(ans, dp[N][i]);
    cout << ans << endl;
}
