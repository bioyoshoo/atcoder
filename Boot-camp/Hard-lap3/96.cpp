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

    vector<vector<int>> ans;
    rep(i, H - 1) {
        rep(j, W) {
            if (A[i][j] % 2 == 1) {
                A[i][j]--;
                A[i + 1][j]++;
                ans.push_back({i, j, i + 1, j});
            }
        }
    }
    rep(j, W - 1) {
        if (A[H - 1][j] % 2 == 1) {
            A[H - 1][j]--;
            A[H - 1][j + 1]++;
            ans.push_back({H - 1, j, H - 1, j + 1});
        }
    }
    int n = (int)ans.size();
    cout << n << endl;
    rep(i, n) rep(j, 4) {
        cout << ans[i][j] + 1 ;
        if (j == 3) cout << endl;
        else cout << " ";
    }
}