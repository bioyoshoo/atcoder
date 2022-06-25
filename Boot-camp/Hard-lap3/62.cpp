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
        int cnt = 0;
        int left = 0, right = 0;
        for (int left = 0; left < W;) {
            while (right < N && S[left] == S[right]) {
                right++;
                cnt++;
            }
            if (S[left] == '.') {
                for (int j = left; j < right; j++) R[i][j] = 
            }
            if (right == left) right++;
            left = right;
        }
    }
}