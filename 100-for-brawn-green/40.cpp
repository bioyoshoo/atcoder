#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e4;

int main() {
    int N, K; cin >> N >> K;
    vector<int> S(N + 1, -1);
    rep(i, K) {
        int a, b; cin >> a >> b; b--;
        S[a] = b;
    }

    ll dp[110][5][5];
    memset(dp, 0, sizeof(dp));

    if (S[1] != -1) dp[1][S[1]][1] = 1;
    else {
        rep(i, 3) dp[1][i][1] = 1;
    }

    // i日目
    for (int i = 1; i < N; i++) {
        // i日目のパスタの種類
        for (int j = 0; j < 3; j++) {
            // i日目のパスタを連続何日食べているか
            for (int k = 1; k <= 2; k++) {
                // i+1日目のパスタの種類
                for (int a = 0; a < 3; a++) {

                    // i+1日目のパスタが決まっている場合
                    // 指定されたもの以外とばす
                    if (S[i + 1] != -1 && S[i + 1] != a) continue;

                    // 前日と異なるパスタの場合
                    if (j != a) {
                        dp[i + 1][a][1] += dp[i][j][k];
                        dp[i + 1][a][1] %= mod;
                    }
                    // 前日と同じパスタ(k + 1 = 3にならないように)
                    else if (j == a && k + 1 < 3) {
                        dp[i + 1][a][k + 1] += dp[i][j][k];
                        dp[i + 1][a][k + 1] %= mod;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++) for (int j = 1; j <= 3; j++) {
        ans += dp[N][i][j];
        ans %= mod;
    }
    cout << ans << endl;
}
