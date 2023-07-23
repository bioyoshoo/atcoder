#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int MAX = 2e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

ll dp[110][100010];

int main() {
    int N, W; cin >> N >> W;
    vector<ll> weight(N), value(N);
    rep(i, N) cin >> weight[i] >> value[i];
    
    // dp[i][j] i: i番目まで選ぶ, j: 価値の合計, dp[i][j]: i番目まで見て価値の合計jであるときの重さの最小値
    rep(i, 110) rep(j, 100010) dp[i][j] = MAX;

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 100000; j++) {
            chmin(dp[i + 1][j], dp[i][j]);
            if (j - value[i] >= 0) chmin(dp[i + 1][j], dp[i][j - value[i]] + weight[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100000; i++) if (dp[N][i] <= W) ans = i;
    cout << ans << endl;
}
