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
        }

        if (flag) ans = max(ans, n);
    }

    cout << ans << endl;
}