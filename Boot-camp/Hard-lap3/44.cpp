#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<vector<int>> T(N, vector<int>(N, -1));
    rep(i, N) {
        int a; cin >> a;
        rep(j, a) {
            int x, y; cin >> x >> y; x--;
            T[i][x] = y;
        }
    }

    int ans = 0;
    for (ll i = 0; i < (1LL << N); i++) {
        bool flag = true;
        set<int> h_st;
        rep(j, N) {
            if (i & (1LL << j)) h_st.insert(j);
        }
        for (auto h: h_st) {
            rep(k, N) {
                if (T[h][k] == 0 && h_st.count(k)) flag = false;
                if (T[h][k] == 1 && !h_st.count(k)) flag = false;
            }
        }
        if (flag) ans = max(ans, (int)h_st.size());
    }
    cout << ans << endl;
}