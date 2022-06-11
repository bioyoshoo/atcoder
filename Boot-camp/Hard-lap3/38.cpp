#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> T(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> T[i][j];
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    int ans = -1;
    rep(sx, H) {
        rep(sy, W) {
            if (T[sx][sy] == '#') continue;

            vector<vector<int>> seen(H, vector<int>(W, -1));
            seen[sx][sy] = 0;
            queue<pair<int, int>> todo;
            todo.push({sx, sy});
            while (!todo.empty()) {
                int x, y;
                tie(x, y) = todo.front();
                todo.pop();
                rep(i, 4) {
                    int next_x = x + dx[i], next_y = y + dy[i];
                    if (next_x < 0 || H <= next_x) continue;
                    if (next_y < 0 || W <= next_y) continue;
                    if (seen[next_x][next_y] != -1) continue;
                    if (T[next_x][next_y] == '#') continue;
                    seen[next_x][next_y] = seen[x][y] + 1;
                    todo.push({next_x, next_y});
                }
            }
            rep(i, H) rep(j, W) ans = max(ans, seen[i][j]);
        }
    }
    cout << ans << endl;
}