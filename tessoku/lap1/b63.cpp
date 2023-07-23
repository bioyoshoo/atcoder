#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int R, C; cin >> R >> C;
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx; sy--; sx--; gy--; gx--;
    vector<vector<char>> T(R, vector<char>(C, -1));
    rep(i, R) rep(j, C) cin >> T[i][j];

    vector<vector<int>> dp(R, vector<int>(C, -1));
    vector<int> dy = {0, -1, 0, 1}, dx = {1, 0, -1, 0};

    dp[sy][sx] = 0;
    queue<pair<int, int>> que;
    que.push({sy, sx});

    while (!que.empty()) {
        int y, x; tie(y, x) = que.front();
        que.pop();

        rep(r, 4) {
            int ny = y + dy[r], nx = x + dx[r];
            if (T[ny][nx] == '#' || dp[ny][nx] != -1) continue;
            dp[ny][nx] = dp[y][x] + 1;
            que.push({ny, nx});
        }
    }

    cout << dp[gy][gx] << endl;
}
