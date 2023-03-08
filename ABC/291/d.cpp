#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    int N; cin >> N;
    vector<vector<ll>> AB(N, vector<ll>(2)); 
    rep(i, N) cin >> AB[i][0] >> AB[i][1];

    vector<vector<mint>> dp(N, vector<mint>(2));
    dp[0][0] = dp[0][1] = 1;

    // dp[i][j] i番目 j: 表裏
    rep(i, N - 1) {
        rep(j, 2) {
            rep(k, 2) {
                // i + 1 枚目がj, i 枚目がk
                if (AB[i + 1][j] == AB[i][k]) continue;

                dp[i + 1][j] += dp[i][k];
            }
        }
    }

    mint ans = dp[N - 1][0] + dp[N - 1][1];
    cout << ans.val() << endl;
}
