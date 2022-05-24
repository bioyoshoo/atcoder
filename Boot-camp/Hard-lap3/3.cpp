#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e10;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> S[i][j];

    vector<vector<int>> dp(H, vector<int>(W, INF));
    if (S[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i > 0) {
                if (S[i - 1][j] == '.' && S[i][j] == '#') chmin(dp[i][j], dp[i - 1][j] + 1);
                else chmin(dp[i][j], dp[i - 1][j]);
            }
            if (j > 0) {
                if (S[i][j - 1] == '.' && S[i][j] == '#') chmin(dp[i][j], dp[i][j - 1] + 1);
                else chmin(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}