#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }
    vector<vector<long long>> dp(H, vector<long long>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i > 0 && table[i][j] != '#' && table[i - 1][j] != '#') {
                dp[i][j] += dp[i - 1][j] % mod;
            }
            if (j > 0 && table[i][j] != '#' && table[i][j - 1] != '#') {
                dp[i][j] += dp[i][j - 1] % mod;
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}