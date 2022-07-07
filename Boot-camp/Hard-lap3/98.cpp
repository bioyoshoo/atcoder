#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W; cin >> H >> W;
    vector<int> cnt(26);
    rep(i, H) rep(j, W) {
        char c; cin >> c;
        cnt[(int)(c - 'a')]++;
    }

    int four = 0, two = 0, one = 0;
    if (H % 2 == 0 && W % 2 == 0) {
        four = (H * W) / 4;
    }
    else if (H % 2 == 1 && W % 2 == 1) {
        one = 1; two = H / 2 + W / 2; four = (H * W - one - two) / 4;
    }
    else if (H % 2 == 1) {
        two = W / 2; four = (H * W - two) / 4;
    }
    else {
        two = H / 2; four = (H * W - two) / 4;
    }

    rep(i, 26) {
        int n = min(four, cnt[i] / 4);
        cnt[i] -= 4 * n;
        four -= n;
    }
    rep(i, 26) {
        int n = min(two, cnt[i] / 2);
        cnt[i] -= 2 * n;
        two -= n;
    }
    rep(i, 26) {
        int n = min(one, cnt[i]);
        cnt[i] -= n;
        one -= n;
    }

    bool ans = true;
    rep(i, 26) if (cnt[i] != 0) ans = false;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}