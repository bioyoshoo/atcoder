#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> T(H, vector<char>(W));
    int b = 0;
    rep(i, H) rep(j, W) {
        cin >> T[i][j];
        if (T[i][j] == '#') b++;
    }

    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vector<vector<int>> seen(H, vector<int>(W, -1));
    seen[0][0] = 0;
    queue<pair<int, int>> todo;
    todo.push({0, 0});
    while (!todo.empty()) {
        int x, y;
        tie(x, y) = todo.front();
        todo.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (next_x < 0 || next_x >= H) continue;
            if (next_y < 0 || next_y >= W) continue;
            if (T[next_x][next_y] == '#') continue;
            if (seen[next_x][next_y] != -1) continue;
            seen[next_x][next_y] = seen[x][y] + 1;
            todo.push({next_x, next_y});
        }
    }

    int ans;
    if (seen[H - 1][W - 1] == -1) ans = -1;
    else ans = H * W - (b + seen[H - 1][W - 1] + 1);
    cout << ans << endl;
}