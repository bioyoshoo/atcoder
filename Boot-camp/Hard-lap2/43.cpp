#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> dp(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> dp[i][j];
    }
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == -1) continue;
            ans += dp[A[i][j]][1];
        }
    }

    cout << ans << endl;
}