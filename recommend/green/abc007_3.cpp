#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int R, C; cin >> R >> C;
    int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy; sx--; sy--; gx--; gy--;
    vector<string> table(R);
    rep(i, R) cin >> table[i];

    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vector<vector<int>> seen(R, vector<int>(C, -1));
    queue<pair<int, int>> todo;

    todo.push({sx, sy});
    seen[sx][sy] = 0;
    while (!todo.empty()) {
        int x, y; tie(x, y) = todo.front();
        todo.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (table[next_x][next_y] == '#') continue;
            if (seen[next_x][next_y] != -1) continue;
            seen[next_x][next_y] = seen[x][y] + 1;
            todo.push({next_x, next_y});
        }
    }

    cout << seen[gx][gy] << endl;
}