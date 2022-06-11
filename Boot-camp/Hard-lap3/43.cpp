#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e8;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> dp(10, vector<int>(10, INF));
    rep(i, 10) rep(j, 10) cin >> dp[i][j];
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, H) rep(j, W) {
        if (A[i][j] == -1) continue;
        ans += dp[A[i][j]][1];
    }
    cout << ans << endl;
}