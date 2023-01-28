#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int m; cin >> m;
    int sx, sy; cin >> sx >> sy;
    vector<pair<int, int>> V(m - 1);
    int prev_x = sx, prev_y = sy;
    rep(i, m - 1) {
        int x, y; cin >> x >> y;
        V[i] = {x - prev_x, y - prev_y};
        prev_x = x; prev_y = y;
    }

    int n; cin >> n;
    set<pair<int, int>> st;
    vector<pair<int, int>> M(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        M[i] = {x, y};
        st.insert({x, y});
    }

    int ans_x = -1, ans_y = -1;
    rep(i, n) {
        bool flag = true;
        int gx = M[i].first, gy = M[i].second;

        int x = gx, y = gy;
        rep(j, m - 1) {
            int nx = x + V[j].first, ny = y + V[j].second;
            if (!st.count({nx, ny})) {
                flag = false;
                break;
            }
            x = nx; y = ny;
        }

        if (flag) {
            ans_x = gx - sx; ans_y = gy - sy;
            break;
        }
    }

    cout << ans_x << " " << ans_y << endl;
}
