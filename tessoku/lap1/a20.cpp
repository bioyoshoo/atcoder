#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int dp[2100][2100];

int main() {
    string S, T; cin >> S >> T;
    int m = S.size(), n = T.size();

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i > 0) chmax(dp[i][j], dp[i - 1][j]);

            if (j > 0) chmax(dp[i][j], dp[i][j - 1]);

            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) chmax(dp[i][j], dp[i - 1][j - 1] + 1);
                else chmax(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    cout << dp[m][n] << endl;
}