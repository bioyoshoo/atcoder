#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e15;

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<vector<int64_t>> dp(10, vector<int64_t>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> dp[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a = A[i][j];
            if (a != -1) ans += dp[a][1];
        }
    }

    cout << ans << endl;
}