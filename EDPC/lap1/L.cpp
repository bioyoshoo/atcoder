#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    for (int i = 0; i <= N; i++) dp[i][i] = 0;

    for (int len = 1; len <= N; len++) {
        for (int i = 0; i + len <= N; i++) {
            int j = i + len;

            if ((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1]);
            }
            else {
                dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1]);
            }
        }
    }
    cout << dp[0][N] << endl;
}