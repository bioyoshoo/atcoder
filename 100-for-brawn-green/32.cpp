#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    while (true) {
        int w, h; cin >> w >> h;
        if (w == 0 && h == 0) break;

        vector<vector<int>> V(h, vector<int>(w - 1)), H(h - 1, vector<int>(w));
        rep(i, 2*h - 1) {
            if (i % 2 == 0) {
                rep(j, w - 1) cin >> V[i/2][j];
            }
            else {
                rep(j, w) cin >> H[i/2][j];
            }
        }

        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};

        vector<vector<int>> seen(h, vector<int>(w, 0));
        queue<pair<int, int>> todo;
        seen[0][0] = 1;
        todo.push({0, 0});

        // (i, j) wall up H[i - 1][j], down H[i][j], right V[i][j], left V[i][j - 1]
        while (!todo.empty()) {
            int x, y; 
            tie(x, y) = todo.front();
            todo.pop();

            rep(r, 4) {
                
                // right
                if (r == 0) {
                    if (y == w - 1) continue;
                    if (V[x][y] == 1) continue;
                }
                // up
                else if (r == 1) {
                    if (x == 0) continue;
                    if (H[x - 1][y] == 1) continue;
                }
                // left
                else if (r == 2) {
                    if (y == 0) continue;
                    if (V[x][y - 1] == 1) continue;
                }
                // down
                else if (r == 3) {
                    if (x == h - 1) continue;
                    if (H[x][y] == 1) continue;
                }

                int nx = x + dx[r], ny = y + dy[r];

                if (seen[nx][ny] != 0) continue;

                seen[nx][ny] = seen[x][y] + 1;
                todo.push({nx, ny});
            }
        }

        if (seen[h - 1][w - 1] != -1) cout << seen[h - 1][w - 1] << endl;
        else cout << 0 << endl;
    }
}