#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> T(H, vector<int>(W));
    rep(i, H) rep(j, W) {
        char c; cin >> c;
        if (c == '#') T[i][j]++;
    }

    for (int j = 0; j < W; j++) {
        for (int i = 1; i < H; i++) {
            T[i][j] += T[i - 1][j];
        }
    }
    
    rep(j, W) cout << T[H - 1][j] << " ";
    cout << endl;
}