#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H1, W1; cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    rep(i, H1) rep(j, W1) cin >> A[i][j];

    int H2, W2; cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    rep(i, H2) rep(j, W2) cin >> B[i][j];
    vector<int> B_flatten;
    rep(i, H2) rep(j, W2) B_flatten.push_back(B[i][j]);

    int a = H1 - H2, b = W1 - W2;
    bool ans = false;
    for (ll i = 0; i < (1LL << H1); i++) {
        for (ll j = 0; j < (1LL << W1); j++) {
            set<int> st_h, st_w;
            for (int x = 0; x < H1; x++) if (i & (1LL << x)) st_h.insert(x);
            for (int x = 0; x < W1; x++) if (j & (1LL << x)) st_w.insert(x);
            if ((int)st_h.size() != a || (int)st_w.size() != b) continue;

            vector<int> C;
            rep(c, H1) rep(d, W1) {
                if (st_h.count(c)) continue;
                if (st_w.count(d)) continue;
                C.push_back(A[c][d]);
            }

            if (B_flatten == C) ans = true;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}