#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[10100][2][110];

int main() {
    string K; cin >> K;
    int D; cin >> D;
    int N = K.size();
    vector<int> S(N);
    for (int i = 0; i < N; i++) S[i] = (int)(K[i] - '0');

    dp[0][0][0] = 1;
    rep(i, N) rep(d, D) {
        rep(x, S[i]) {
            dp[i + 1][1][(d + x) % D] += dp[i][0][d] % mod;
            dp[i + 1][1][(d + x) % D] %= mod;
        }
        dp[i + 1][0][(d + S[i]) % D] += dp[i][0][d] % mod;
        dp[i + 1][0][(d + S[i]) % D] %= mod;
        
        rep(x, 10) {
            dp[i + 1][1][(d + x) % D] += dp[i][1][d] % mod;
            dp[i + 1][1][(d + x) % D] %= mod;
        }
    }
    ll ans = dp[N][0][0] + dp[N][1][0] - 1;
    if (ans < 0) ans += mod;
    cout << ans << endl;
}