#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> G[i][j];

    vector<vector<int>> seen(H, vector<int>(W));

    int x = 0, y = 0;
    seen[x][y] = 1;
    bool loop = false;
    while (true) {
        int nx = x, ny = y;
        if (x != 0 && G[x][y] == 'U') nx -= 1;
        else if (x != H - 1 && G[x][y] == 'D') nx += 1;
        else if (y != 0 && G[x][y] == 'L') ny -= 1;
        else if (y != W - 1 && G[x][y] == 'R') ny += 1;
        else break;
        
        if (seen[nx][ny] != 0) {
            loop = true;
            break;
        }
        seen[nx][ny] = 1;
        x = nx; y = ny;
    }

    if (loop) cout << -1 << endl;
    else cout << x + 1 << " " << y + 1 << endl;
}