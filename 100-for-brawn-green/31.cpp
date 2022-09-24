#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int W, H; cin >> W >> H;
    vector<vector<int>> T(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> T[i][j];

    vector<int> dw1 = {1, 1, 0, -1, 0, 1}, dh1 = {0, -1, -1, 0, 1, 1};
    vector<int> dw2 = {1, 0, -1, -1, -1, 0}, dh2 = {0, -1, -1, 0, 1, 1};

    vector<vector<int>> island(H, vector<int>(W, -1));
    vector<int> closed_ids;
    int id = 0;
    rep(j, W) rep(i, H) {
        if (T[i][j] != 0) continue;
        if (island[i][j] != -1) continue;

        bool closed = true;
        island[i][j] = id;
        queue<pair<int, int>> todo;
        todo.push({i, j});

        while (!todo.empty()) {
            int h, w; tie(h, w) = todo.front();
            todo.pop();

            vector<int> dw, dh;
            if (h % 2 == 0) {
                dw = dw1; dh = dh1;
            }
            else {
                dw = dw2; dh = dh2;
            }

            rep(r, 6) {
                int nw = w + dw[r], nh = h + dh[r];
                if (nw < 0 || nw >= W) {
                    closed = false;
                    continue;
                }
                else if (nh < 0 || nh >= H) {
                    closed = false;
                    continue;
                }
                else if (island[nh][nw] != -1) continue;
                else if (T[nh][nw] == 1) continue;

                island[nh][nw] = id;
                todo.push({nh, nw});
            }
        }

        if (closed) closed_ids.push_back(id);
        id++;
    }
        
    for (auto d: closed_ids) {
        rep(i, H) rep(j, W) {
            if (island[i][j] == d) T[i][j] = 1;
        }
    }

    vector<vector<int>> seen(H, vector<int>(W, -1));
    rep(sj, W) rep(si, H) {
        if (T[si][sj] != 1) continue;
        if (seen[si][sj] != -1) continue;
        
        queue<pair<int, int>> todo;
        todo.push({si, sj});

        while (!todo.empty()) {
            int h, w; tie(h, w) = todo.front();
            todo.pop();

            int v = 0;
            rep(r, 6) {
                int nh, nw;
                if (h % 2 == 0) {
                    nh = h + dh1[r], nw = w + dw1[r];
                }
                else {
                    nh = h + dh2[r], nw = w + dw2[r];
                }
                
                if (nw < 0 || nw >= W) {
                    v++;
                    continue;
                }
                else if (nh < 0 || nh >= H) {
                    v++;
                    continue;
                }
                else if (T[nh][nw] == 0) {
                    v++;
                    continue;
                }
                else if (seen[nh][nw] != -1) continue;

                todo.push({nh, nw});
            }
            
            seen[h][w] = v;
        }
    }

    int ans = 0;
    rep(i, H) rep(j, W) {
        if (seen[i][j] == -1) continue;
        ans += seen[i][j];
    }

    cout << ans << endl;
}
