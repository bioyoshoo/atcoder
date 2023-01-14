#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int A[510][510];

int main() {
    int N; cin >> N;
    rep(i, N) rep(j, N) cin >> A[i][j];

    map<int, int> R;
    rep(i, N) R[i] = i;

    int Q; cin >> Q;
    rep(i, Q) {
        int q, x, y; cin >> q >> x >> y; x--; y--;

        if (q == 1) {
            int rx = R[x], ry = R[y];
            R[x] = ry, R[y] = rx;
        }

        else if (q == 2) {
            cout << A[R[x]][y] << endl;
        }
    }
}
