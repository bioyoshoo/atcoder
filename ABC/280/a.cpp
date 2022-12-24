#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<string> X(H);
    rep(i, H) cin >> X[i];

    int ans = 0;
    rep(i, H) rep(j, W) {
        if (X[i][j] == '#') ans++;
    }

    cout << ans << endl;
}