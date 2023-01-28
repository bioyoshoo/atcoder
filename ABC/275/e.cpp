#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    int N, M, K; cin >> N >> M >> K;

    vector<vector<mint>> dp(K + 1, vector<mint>(N + 1));
    dp[0][0] = 1;
    mint m_inv = mint(1) / M;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            for (int m = 1; m <= M; m++) {
                if (j + m <= N) dp[i + 1][j + m] += dp[i][j] * m_inv;
                else dp[i + 1][N - ((j + m) % N)] += dp[i][j] * m_inv;
            }
        }
    }

    mint ans = 0;
    for (int i = 0; i <= K; i++) ans += dp[i][N];

    cout << ans.val() << endl;
}
