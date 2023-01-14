#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int MAX = 3000;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int dp[2010][2010];

int main() {
    string S, T; cin >> S >> T;
    int m = S.size(), n = T.size();
    rep(i, 2010) rep(j, 2010) dp[i][j] = MAX;

    dp[0][0] = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) chmin(dp[i][j], dp[i - 1][j - 1]);
                else chmin(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);
            if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    cout << dp[m][n] << endl;
}
