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

int N, M, K;
int A[60], B[60];

int dp[60][300], score[300][300];

int main() {
    cin >> N >> M >> K;
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, 60) rep(j, 300) dp[i][j] = -1e9;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            int cnt = 0;
            rep(k, M) {
                if (i <= A[k] && B[k] <= j) cnt++;
            }
            score[i][j] = cnt;
        }
    }

    // dp[i][j] i 番目の章まで分けたとき、最後のページが j であるときの良さの最大値
    dp[0][0] = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k <= j - 1; k++) {
                chmax(dp[i + 1][j], dp[i][k] + score[k + 1][j]);
            }
        }
    }

    cout << dp[K][N] << endl;
}
