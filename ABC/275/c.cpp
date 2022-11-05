#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool check(int x, int y) {
    if ((x < 0) || (x >= 9)) return false;
    if ((y < 0) || (y >= 9)) return false;
    return true;
}
int main() {
    vector<string> T(9);
    rep(i, 9) cin >> T[i];

    set<vector<pair<int, int>>> st;
    rep(sx, 9) rep(sy, 9) {
        rep(a, 9) rep(b, 9) {
            // not move
            if ((a == 0) && (b == 0)) continue;
            if (T[sx][sy] != '#') continue;
            
            bool ok = true;
            vector<int> dx = {a, -b, -a, b}, dy = {b, a, -b, -a};
            int x = sx, y = sy;
            vector<pair<int, int>> f;

            rep(r, 4) {
                int nx = x + dx[r], ny = y + dy[r];
                if (check(nx, ny) && T[nx][ny] == '#') {
                    x = nx, y = ny;
                    f.push_back({x, y});
                }
                else {
                    ok = false;
                    break;
                }
            }
            
            if (ok) {
                sort(f.begin(), f.end());
                st.insert(f);
            }
        }
    }

    cout << st.size() << endl;
}
