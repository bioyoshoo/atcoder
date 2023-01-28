#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using cord = pair<int, int>;

cord search(vector<vector<char>> &T, char c) {
    int x = -1, y = -1;
    int H = T.size(), W = T[0].size();
    rep(i, H) rep(j, W) {
        if (T[i][j] == c) {
            x = i; y = j;
            break;
        }
    }
    return {x, y};
}

int main() {
    int H, W, N; cin >> H >> W >> N;
    vector<vector<char>> T(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> T[i][j];

    vector<cord> S(N + 1);
    S[0] = search(T, 'S');
    for (int i = 1; i <= N; i++) S[i] = search(T, (char)('0' + i));

    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    ll ans = 0;
    rep(i, N) {
        int sx, sy; tie(sx, sy) = S[i];
        int gx, gy; tie(gx, gy) = S[i + 1];

        vector<vector<int>> seen(H, vector<int>(W, -1));
        queue<cord> todo;
        seen[sx][sy] = 0;
        todo.push({sx, sy});

        while (!todo.empty()) {
            int x, y; tie(x, y) = todo.front();
            todo.pop();
            rep(i, 4) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= H) continue;
                if (ny < 0 || ny >= W) continue;
                if (T[nx][ny] == 'X') continue;
                if (seen[nx][ny] != -1) continue;
                seen[nx][ny] = seen[x][y] + 1;
                todo.push({nx, ny});
            }
        }

        ans += seen[gx][gy];
    }

    cout << ans << endl;
}
