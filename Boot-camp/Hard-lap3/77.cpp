#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<int>> ans(H, vector<int>(W));
    rep(i, B) rep(j, A) ans[i][j] = 1;
    for (int i = B; i < H; i++) for (int j = A; j < W; j++) ans[i][j] = 1;

    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j];
            if (j == W - 1) cout << endl;
        }
    }
}