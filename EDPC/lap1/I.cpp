#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long double> P(N);
    for (int i = 0; i < N; i++) cin >> P.at(i);

    vector<vector<long double>> dp(N + 1, vector<long double>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] += dp[i][j] * (1 - P[i]);
            dp[i + 1][j + 1] += dp[i][j] * P[i];
        }
    }

    long double ans = 0;
    for (int i = N / 2 + 1; i <= N; i++) ans += dp[N][i];
    cout << fixed << setprecision(12);
    cout << ans << endl;
}