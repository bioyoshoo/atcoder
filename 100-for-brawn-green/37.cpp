#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e15;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<ll> C(m); rep(i, m) cin >> C[i];

    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, INF));
    dp[0][0] = 0;

    rep(i, m) {
        rep(j, n + 1) {
            chmin(dp[i + 1][j], dp[i][j]);
            if (j - C[i] >= 0) chmin(dp[i + 1][j], dp[i + 1][j - C[i]] + 1);
        }
    }

    cout << dp[m][n] << endl;
}