#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    
    vector<vector<ll>> dp(61, vector<ll>(N));
    rep(i, N) {
        ll a; cin >> a; a--;
        dp[0][i] = a;
    }
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
    ll ans = 0;
    for (ll i = 0; i < 61; i++) {
        if (K & (1LL << i)) ans = dp[i][ans];
    }
    ans++;
    cout << ans << endl;
}