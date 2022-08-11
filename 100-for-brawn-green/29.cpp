#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;

    vector<vector<char>> T(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> T[i][j];
    vector<vector<int>> seen(H, vector<int>(W, -1));
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    seen[sx][sy] = 0;
    queue<pair<int, int>> todo;
    todo.push({sx, sy});
    while (!todo.empty()) {
        int x, y;
        tie(x, y) = todo.front();
        todo.pop();
        rep(r, 4) {
            int x2 = x + dx[r], y2 = y + dy[r];
            if (T[x2][y2] == '#') continue;
            if (seen[x2][y2] != -1) continue;
            seen[x2][y2] = seen[x][y] + 1;
            todo.push({x2, y2});
        }
    }

    cout << seen[gx][gy] << endl;
}