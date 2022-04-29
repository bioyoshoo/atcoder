#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int64_t blacks = 0;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            if (c == '#') blacks++;
            table.at(i).at(j) = c;
        }
    }

    vector<vector<int>> seen(H, vector<int>(W, -1));
    seen[0][0] = 1;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    queue<pair<int, int>> todo;
    todo.push({0, 0});

    while (!todo.empty()) {
        int x, y;
        tie(x, y) = todo.front();
        todo.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (next_x < 0 || H <= next_x) continue;
            if (next_y < 0 || W <= next_y) continue;
            if (table[next_x][next_y] == '#') continue;
            if (seen[next_x][next_y] != -1) continue;
            seen[next_x][next_y] = seen[x][y] + 1;
            todo.push({next_x, next_y});
        }
    }

    if (seen[H - 1][W - 1] == -1) cout << -1 << endl;
    else {
        int64_t ans = H * W - seen[H - 1][W - 1] - blacks;
        cout << ans << endl;
    }
}