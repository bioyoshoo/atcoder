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
