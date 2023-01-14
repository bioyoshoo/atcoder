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

int dp[1010][1010];

int main() {
    int N; string S; cin >> N >> S;
    string T = S;
    reverse(T.begin(), T.end());

    rep(i, 1010) rep(j, 1010) dp[i][j] = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) chmax(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            if (i > 0) chmax(dp[i][j], dp[i - 1][j]);
            if (j > 0) chmax(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[N][N] << endl;
}
