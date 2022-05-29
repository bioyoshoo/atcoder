#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<string> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    bool ans = false;
    rep(sx, N) {
        rep(sy, N) {
            if (sx + M > N || sy + M > N) continue;
            bool flag = true;
            rep(x, M) {
                rep(y, M) {
                    if (A[sx + x][sy + y] != B[x][y]) flag = false;
                }
            }
            if (flag) ans = true;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}