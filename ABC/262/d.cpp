#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 998244353;

ll dp[110][110][110];

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    // 選ぶ個数
    for (int n = 1; n <= N; n++) {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k < N; k++) {
                    // 選ぶ
                    dp[i + 1][j + 1][(k + A[i]) % n] += dp[i][j][k];
                    dp[i + 1][j + 1][(k + A[i]) % n] %= mod;

                    // 選ばない
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= mod;
                }
            }
        }
        ans += dp[N][n][0];
        ans %= mod;
    }
    cout << ans << endl;
}