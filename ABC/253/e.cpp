#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;
const ll mod = 998244353;

int main() {
    ll N, M, K; cin >> N >> M >> K;

    ll dp[1010][5010];
    for (int i = 1; i <= M; i++) dp[0][i] = 1;
    
    for (int i = 0; i < N - 1; i++) {
        ll sum[5010];
        for (int j = 1; j <= M; j++) {
            sum[j] = dp[i][j] + sum[j - 1] % mod;
            sum[j] %= mod;
        }
        
        for (int j = 1; j <= M; j++) {
            if (j - K > 0) {
                dp[i + 1][j] += sum[j - K] - sum[0];
                dp[i + 1][j] %= mod;
            }
            if (j + K <= M) {
                dp[i + 1][j] += sum[M] - sum[j + K - 1];
                dp[i + 1][j] %= mod;
            }
        }
    }

    mint ans = 0;
    for (int i = 1; i <= M; i++) ans += dp[N][i];
    cout << ans.val() << endl;
}