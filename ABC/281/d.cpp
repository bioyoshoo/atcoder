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

ll dp[110][110][110];

int main() {
    ll N, K, D; cin >> N >> K >> D;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < D; k++) {

                if (dp[i][j][k] == -1) continue;

                chmax(dp[i + 1][j][k], dp[i][j][k]);
                
                if (j < K) chmax(dp[i + 1][j + 1][(k + A[i]) % D], dp[i][j][k] + A[i]);
            }
        }
    }

    cout << dp[N][K][0] << endl;
}
