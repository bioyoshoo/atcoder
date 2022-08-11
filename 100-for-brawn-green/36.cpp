#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, W; cin >> N >> W;
    vector<int> value(N), weight(N);
    rep(i, N) cin >> value[i] >> weight[i];

    vector<vector<int>> dp(N + 1, vector<int>(W + 1));
    dp[0][0] = 0;

    rep(i, N) {
        rep(j, W + 1) {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j - weight[i] >= 0) chmax(dp[i + 1][j], dp[i + 1][j - weight[i]] + value[i]);
        }
    }

    int ans = 0;
    rep(x, W + 1) chmax(ans, dp[N][x]);
    cout << ans << endl;
}