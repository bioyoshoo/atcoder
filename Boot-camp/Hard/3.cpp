#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1LL << 60;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    vector<int> dx = {0, 1}, dy = {1, 0};
    vector<vector<int64_t>> dp(H, vector<int64_t>(W, INF));
    if (table[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int dir = 0; dir < 2; dir++) {
                int ni = i + dx[dir], nj = j + dy[dir];

                if (ni >= H || nj >= W) continue;

                int add = 0;
                if (table[ni][nj] == '#' && table[i][j] == '.') add = 1;
                chmin(dp[ni][nj], dp[i][j] + add);
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}