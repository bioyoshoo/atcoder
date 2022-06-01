#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    vector<vector<int>> ans(H, vector<int>(W));
    int c = 0;
    for (int i = 0; i < H; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < W; j++) {
                ans[i][j] = c + 1;
                A[c]--;
                if (A[c] == 0) c++;
            }
        }
        else {
            for (int j = W - 1; j >= 0; j--) {
                ans[i][j] = c + 1;
                A[c]--;
                if (A[c] == 0) c++;
            }
        }
    }
    rep(i, H) rep(j, W) {
        cout << ans[i][j] << " ";
        if (j == W - 1) cout << endl;
    }
}