#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
<<<<<<< HEAD

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
=======
using cord = pair<int, int>;

int main() {
    int m; cin >> m;
    vector<int> TX(m), TY(m);
    rep(i, m) cin >> TX[i] >> TY[i];
    int n; cin >> n;
    vector<int> SX(n), SY(n);
    set<pair<int, int>> st;
    rep(i, n) {
        cin >> SX[i] >> SY[i];
        st.insert({SX[i], SY[i]});
    }
    
    rep(i, n) {
        int x = SX[i], y = SY[i];
        bool ans = true;
        rep(j, m - 1) {
            int nx = x + TX[j + 1] - TX[j], ny = y + TY[j + 1] - TY[j];

            if (st.count({nx, ny})) x = nx, y = ny;
            else {
                ans = false;
                break;
            }
        }

        if (ans) {
            cout << SX[i] - TX[0] << " " << SY[i] - TY[0] << endl;
            break;
        }
    }
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
}
