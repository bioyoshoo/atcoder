#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e10;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t H, N;
    cin >> H >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(H + 1, MAX));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H + 1; j++) {
            chmin(dp[i][min(H, j + A[i])], dp[i][j] + B[i]);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << dp[N][H] << endl;
}