#include <bits/stdc++.h>
using namespace std;
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

ll f(ll y) {
    if (y < 0) return 0;
    if (y > 255) return 255;
    return y;
}

int main() {
    while (true) {
        int N, M; cin >> N >> M;
        if ((N == 0) && (M == 0)) break;

        vector<ll> C(M); rep(i, M) cin >> C[i];
        vector<ll> X(N + 1); rep(i, N) cin >> X[i + 1];

        vector<vector<ll>> dp(N + 1, vector<ll>(256, INF));
        dp[0][128] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < M; k++) {
                    ll nj = f(j + C[k]);
                    ll e = (X[i + 1] - nj)*(X[i + 1] - nj);

                    chmin(dp[i + 1][nj], dp[i][j] + e);
                }
            }
        }

        ll ans = INF;
        rep(i, 256) chmin(ans, dp[N][i]);
        cout << ans << '\n';
    }
}
