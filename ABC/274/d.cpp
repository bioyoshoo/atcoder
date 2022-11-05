#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, x, y; cin >> N >> x >> y;
    if (x < 0) x = -x;
    if (y < 0) y = -y;

    vector<int> A, B;
    rep(i, N) {
        int a; cin >> a;
        if (i % 2 == 0) A.push_back(a);
        else B.push_back(a);
    }
    int m = A.size(), n = B.size();

    bool dpx[1010][10010];
    memset(dpx, false, sizeof(dpx));
    // dpx[0][0] = true;
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j <= 10000; j++) {
    //         if (dpx[i - 1][j]) {
    //             dpx[i][j + A[i - 1]] = true;
    //             dpx[i][abs(j - A[i - 1])] = true;
    //         }
    //     }
    // }

    // bool dpy[1010][10010];
    // memset(dpy, false, sizeof(dpy));
    // dpy[0][0] = true;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= 10000; j++) {
    //         if (dpy[i - 1][j]) {
    //             dpy[i][j + A[i - 1]] = true;
    //             dpy[i][abs(j - A[i - 1])] = true;
    //         }
    //     }
    // }

    // if (dpx[m][x] && dpy[n][y]) cout << "Yes" << endl;
    // else cout << "No" << endl;
}