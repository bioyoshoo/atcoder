#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
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
}
