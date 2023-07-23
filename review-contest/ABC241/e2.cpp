#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; ll K; cin >> N >> K;
    vector<vector<ll>> dp(41, vector<ll>(N));

    rep(i, N) cin >> dp[0][i];

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][j] + dp[i][(j + dp[i][j]) % N];
        }
    }

    ll ans = 0;
    for (int i = 0; i < 41; i++) {
        if (K & (1LL << i)) ans += dp[i][ans % N];
    }

    cout << ans << endl;
}
