#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> X(H + 1, vector<int>(W + 1));
    rep(i, H) rep(j, W) cin >> X[i + 1][j + 1];

    rep(i, H + 1) for (int j = 1; j < W + 1; j++) X[i][j] += X[i][j - 1];
    rep(j, W + 1) for (int i = 1; i < H + 1; i++) X[i][j] += X[i - 1][j];

    int Q; cin >> Q;
    rep(i, Q) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        
        int ans = X[c][d] - X[c][b - 1] - X[a - 1][d] + X[a - 1][b - 1];
        cout << ans << endl;
    }
}