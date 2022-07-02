#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    vector<pair<int, int>> S;
    rep(i, H) rep(j, W) {
        cin >> A[i][j];
        if (A[i][j] == '#') S.push_back({i, j});
    }

    vector<vector<int>> seen(H, vector<int>(W, -1));
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    queue<pair<int, int>> todo;
    for (auto [sx, sy]: S) {
        seen[sx][sy] = 0;
        todo.push({sx, sy});
    }

    while (!todo.empty()) {
        int x, y;
        tie(x, y) = todo.front();
        todo.pop();
        rep(r, 4) {
            int next_x = x + dx[r],  next_y = y + dy[r];
            if (!(0 <= next_x && next_x < H)) continue;
            if (!(0 <= next_y && next_y < W)) continue;
            if (A[next_x][next_y] == '#') continue;
            if (seen[next_x][next_y] != -1) continue;
            seen[next_x][next_y] = seen[x][y] + 1;
            todo.push({next_x, next_y});
        }
    }

    int ans = -1;
    rep(i, H) rep(j, W) ans = max(ans, seen[i][j]);
    cout << ans << endl;
}