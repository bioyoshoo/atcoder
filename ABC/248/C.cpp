#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 998244353;

int main() {
    int64_t N, M, K;
    cin >> N >> M >> K;

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(K + 1, 0));
    dp[0][0] = 1;

    for (int n = 0; n < N; n++) {
        for (int sum = 0; sum <= K; sum++) {
            for (int a = 1; a <= M; a++) {
                if (sum + a <= K) dp[n + 1][sum + a] += dp[n][sum] % MAX; 
            }
        }
    }

    int64_t ans = 0;
    for (int k = 0; k <= K; k++) ans += dp[N][k] % MAX;
    cout << ans % MAX << endl;
}