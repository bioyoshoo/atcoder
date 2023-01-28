#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int R, C; cin >> R >> C;
    vector<vector<int>> T(R, vector<int>(C));
    rep(i, R) rep(j, C) cin >> T[i][j];

    int ans = 0;
<<<<<<< HEAD
    // i: 行の状態
    for (ll i = 0; i < (1LL << R); i++) {
        int cnt = 0;
        // j: 列
        rep(j, C) {
            int cnt_c = 0;
            // k: 行の状態
            rep(k, R) {
                if (i & (1LL << k)) cnt_c += T[k][j];
                else cnt_c += 1 - T[k][j];
            }
            cnt += max(cnt_c, R - cnt_c);
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
=======
    for (ll i = 0; i < (1LL << R); i++) {
        set<int> st;
        rep(j, R) if (i & (1LL << j)) st.insert(j);

        int sum = 0;
        rep(j, C) {
            int cnt = 0;
            rep(k, R) {
                if (!st.count(k) && T[k][j] == 1) cnt++;
                else if (st.count(k) && T[k][j] == 0) cnt++;
            }
            sum += max(cnt, R - cnt);
        }

        ans = max(ans, sum);
    }
    cout << ans << endl;
}
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
