#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, P;
    cin >> N >> P;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<vector<int64_t>> dp(N, vector<int64_t>(2, 0));
    if (A[0] % 2 == 0) dp[0][0] = 2;
    else {
        dp[0][0] = 1;
        dp[0][1] = 1;
    }

    for (int n = 1; n < N; n++) {
        if (A[n] % 2 == 0) {
            dp[n][0] = 2 * dp[n - 1][0];
            dp[n][1] = 2 * dp[n - 1][1];
        }
        else {
            dp[n][0] = dp[n - 1][0] + dp[n - 1][1];
            dp[n][1] = dp[n - 1][0] + dp[n - 1][1];
        }
    }

    cout << dp[N - 1][P] << endl;
}