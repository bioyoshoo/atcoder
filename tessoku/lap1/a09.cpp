#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int X[2000][2000];

int main() {
    int H, W, N; cin >> H >> W >> N;

    rep(i, N) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        X[a][b] += 1; X[a][d + 1] += -1; X[c + 1][b] += -1; X[c + 1][d + 1] += 1;
    }

    rep(i, H + 1) rep(j, W + 1) X[i][j + 1] += X[i][j];
    rep(j, W + 1) rep(i, H + 1) X[i + 1][j] += X[i][j];

    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            cout << X[i][j] << " ";
            if (j == W) cout << endl;
        }
    }
}
