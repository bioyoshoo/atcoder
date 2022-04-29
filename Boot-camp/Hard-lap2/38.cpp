#include <bits/stdc++.h>
using namespace std;

void BFS(const vector<vector<char>> &table, vector<vector<int>> &seen, pair<int, int> start) {
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int H = table.size(), W = table[0].size();
    int s_x = start.first, s_y = start.second;
    seen[s_x][s_y] = 0;
    queue<pair<int, int>> todo;
    todo.push(start);

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
}

void chmax(int &a, int b) {
    if (a < b) a = b;
    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    int ans = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] == '#') continue;
            vector<vector<int>> seen(H, vector<int>(W, -1));
            pair<int, int> start = {i, j};
            BFS(table, seen, start);

            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) chmax(ans, seen[h][w]);
            }
        }
    }

    cout << ans << endl;
}