#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> table.at(i).at(j);

    vector<vector<int>> dp(H, vector<int>(W, MAX));
    if (table[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (h - 1 >= 0) {
                if (table[h - 1][w] == '.' && table[h][w] == '#') chmin(dp[h][w], dp[h - 1][w] + 1);
                else chmin(dp[h][w], dp[h - 1][w]);
            }
            if (w - 1 >= 0) {
                if (table[h][w - 1] == '.' && table[h][w] == '#') chmin(dp[h][w], dp[h][w - 1] + 1);
                else chmin(dp[h][w], dp[h][w - 1]);
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}