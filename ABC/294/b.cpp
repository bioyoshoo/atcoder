#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vector<vector<char>> ans(H, vector<char>(W));
    rep(i, H) rep(j, W) {
        if (A[i][j] == 0) ans[i][j] = '.';
        else ans[i][j] = (char)(A[i][j] - 1 + 'A');
    }

    rep(i, H) rep(j, W) {
        cout << ans[i][j];
        if (j == W - 1) cout << endl;
    }
}