#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W, K; cin >> H >> W >> K;
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> C[i][j];

    int ans = 0;
    for (int i = 0; i < (1 << H); i++) {
        vector<vector<char>> D = C;
        int steps = K;
        
        rep(h, H) {
            if (i & (1 << h)) {
                rep(w, W) D[h][w] = '#';
                steps -= 1;
            }
        }
        
        if (steps < 0) continue;

        vector<pair<int, int>> col_white(W);
        rep(w, W) {
            int white = 0;
            rep(h, H) {
                if (D[h][w] == '.') white += 1;
            }
            col_white[w] = make_pair(white, w);
        }

        sort(col_white.rbegin(), col_white.rend());

        rep(k, steps) {
            int w = col_white[k].second;
            rep(h, H) D[h][w] = '#';
        }

        int cand = 0;
        rep(h, H) rep(w, W) if (D[h][w] == '#') cand++;

        ans = max(ans, cand);
    }
    
    cout << ans << endl;
}
