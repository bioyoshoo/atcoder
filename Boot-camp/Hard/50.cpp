#include <bits/stdc++.h>
using namespace std;

void BFS(const vector<vector<char>> &table, int x, int y, vector<vector<int>> &seen) {
    int H = (int)table.size(), W = (int)table.at(0).size();
    vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
    
    seen[x][y] = 1;
    queue<pair<int, int>> todo;
    todo.push({x, y});

    while (!todo.empty()) {
        tie(x, y) = todo.front();
        todo.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i], new_y = y + dy[i];
            if (new_x >= 0 && new_x < H && new_y >= 0 && new_y < W && table[x][y] != '#') {
                if (seen[new_x][new_y] != -1) continue;
                seen[new_x][new_y] = seen[x][y] + 1;
                todo.push({new_x, new_y});
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    int blacks = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> table.at(i).at(j);
            if (table[i][j] == '#') blacks++;
        }
    }

    vector<vector<int>> seen(H, vector<int>(W, -1));
    BFS(table, 0, 0, seen);

    if (seen[H - 1][W - 1] == -1) cout << -1 << endl;
    else cout << H * W - seen[H - 1][W - 1] - blacks << endl;
}