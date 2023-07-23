#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> C[i][j];

    vector<vector<ll>> dp(H, vector<ll>(W));
    dp[0][0] = 1;

    rep(i, H) rep(j, W) {
        
        if (C[i][j] == '#') continue;

        if (i > 0) dp[i][j] += dp[i - 1][j];
        if (j > 0) dp[i][j] += dp[i][j - 1];
    }

    cout << dp[H - 1][W - 1] << endl;
}