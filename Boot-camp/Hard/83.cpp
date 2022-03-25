#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

vector<vector<int>> BFS(vector<vector<char>> &table) {
    vector<int> dh = {1, 0, -1, 0}, dw = {0, 1, 0, -1};
    int H = table.size(), W = table.at(0).size();
    vector<vector<int>> seen(H, vector<int>(W, 0));

    queue<pair<int, int>> todo;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] == '#') todo.push(make_pair(i, j));
        }
    }

    while (!todo.empty()) {
        pair<int, int> p = todo.front();
        todo.pop();

        int h = p.first, w = p.second;
        for (int i = 0; i < 4; i++) {
            int new_h = h + dh[i], new_w = w + dw[i];
            if (0 < new_h && new_h < H && 0 < new_w && new_w < W) {
                if (table[new_h][new_w] == '#') continue;
                todo.push(make_pair(new_h, new_w));
                table[new_h][new_w] = '#';
                seen[new_h][new_w] = seen[h][w] + 1;
            }
        }
    }
    return seen;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table[i][j];
    }

    vector<vector<int>> seen;
    seen = BFS(table);
    int ans = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) chmax(ans, seen[i][j]);
    }

    cout << ans << endl;
}