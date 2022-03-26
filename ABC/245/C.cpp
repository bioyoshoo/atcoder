#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    vector<vector<int>> dp(N, vector<int>(2, 0));
    dp.at(0) = {1, 1};
    for (int64_t i = 1; i < N; i++) {
        if (dp[i - 1][0] == 1 && abs(A[i - 1] - A[i]) <= K) dp[i][0] = 1;
        if (dp[i - 1][1] == 1 && abs(B[i - 1] - A[i]) <= K) dp[i][0] = 1;
        if (dp[i - 1][0] == 1 && abs(A[i - 1] - B[i]) <= K) dp[i][1] = 1;
        if (dp[i - 1][1] == 1 && abs(B[i - 1] - B[i]) <= K) dp[i][1] = 1;
    }

    if (dp[N - 1][0] == 1 || dp[N - 1][1] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}