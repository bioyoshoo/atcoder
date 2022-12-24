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
    int N; cin >> N;
    vector<vector<int>> S(N, vector<int>(3));
    rep(i, 5) {
        rep(j, N) {
            char c; cin >> c;
            if (c == 'R') S[j][0]++;
            else if (c == 'B') S[j][1]++;
            else if (c == 'W') S[j][2]++;
        }
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(3, INF));
    rep(i, 3) dp[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            chmin(dp[i][j], dp[i - 1][(j + 1) % 3] + 5 - S[i - 1][j]);
            chmin(dp[i][j], dp[i - 1][(j + 2) % 3] + 5 - S[i - 1][j]);
        }
    }

    ll ans = INF;
    rep(j, 3) chmin(ans, dp[N][j]);
    cout << ans << endl;
}
