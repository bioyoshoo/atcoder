#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    vector<vector<int>> R(H, vector<int>(W)), C(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        int right = 0;
        for (int left = 0; left < W;) {
            int cnt = 0;
            while (right < W && S[i][left] == S[i][right]) {
                right++;
                cnt++;
            }
            if (S[i][left] == '.') {
                for (int j = left; j < right; j++) R[i][j] = right - left;
            }
            left = right;
        }
    }

    for (int j = 0; j < W; j++) {
        int right = 0;
        for (int left = 0; left < H;) {
            int cnt = 0;
            while (right < H && S[left][j] == S[right][j]) {
                right++;
                cnt++;
            }
            if (S[left][j] == '.') {
                for (int i = left; i < right; i++) C[i][j] = right - left;
            }
            left = right;
        }
    }

    int ans = -1;
    rep(i, H) {
        rep(j, W) {
            ans = max(ans, R[i][j] + C[i][j] - 1);
        }
    }
    cout << ans << endl;
}
