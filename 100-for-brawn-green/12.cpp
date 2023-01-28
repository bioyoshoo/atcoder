#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> T(N, vector<int>(N));
    rep(i, M) {
        int x, y; cin >> x >> y; x--; y--;
<<<<<<< HEAD
        T[x][y] = 1; T[y][x] = 1;
    }

    int ans = 0;
    for (ll i = 0; i < (1LL << N); i++) {
        vector<int> group;
        rep(j, N) {
            if (i & (1LL << j)) group.push_back(j);
        }
        
        bool flag = true;
        int n = group.size();
        rep(j, n) {
            rep(k, n) {
                if (j == k) continue;
                if (T[group[j]][group[k]] != 1) flag = false;
            }
=======
        T[x][y] = 1;; T[y][x] = 1;
    }

    int ans = -1;
    for (ll i = 0; i < (1LL << N); i++) {
        vector<int> V;
        rep(j, N) if (i & (1LL << j)) V.push_back(j);

        bool flag = true;
        int n = V.size();
        rep(a, n) rep(b, n) {
            if (a == b) continue;
            if (T[V[a]][V[b]] != 1) flag = false;
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
        }

        if (flag) ans = max(ans, n);
    }

    cout << ans << endl;
<<<<<<< HEAD
}
=======
}
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
