#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e7;

void BFS(const vector<vector<char>> &table, vector<vector<int>> &seen, vector<pair<int, int>> start) {
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int H = table.size(), W = table[0].size();
    queue<pair<int, int>> todo;
    for (auto [sx, sy]: start) {
        seen[sx][sy] = 0;
        todo.push({sx, sy});
    }
    while (!todo.empty()) {
        int x, y;
        tie(x, y) = todo.front();
        todo.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (next_x < 0 || next_x >= H) continue;
            if (next_y < 0 || next_y >= W) continue;
            if (table[next_x][next_y] == '#') continue;
            if (seen[next_x][next_y] != -1) continue;
            seen[next_x][next_y] = seen[x][y] + 1;
            todo.push({next_x, next_y});
        }
    }
}

int main() {
    int64_t H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    vector<pair<int, int>> start;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c; table.at(i).at(j) = c;
            if (c == '#') start.push_back({i, j});
        }
    }

    vector<vector<int>> seen(H, vector<int>(W, -1));
    BFS(table, seen, start);
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, seen[i][j]);
        }
    }
    cout << ans << endl;
}