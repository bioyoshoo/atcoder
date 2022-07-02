#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N), H(N);
    rep(i, N) cin >> X[i] >> Y[i] >> H[i];

    bool flag = false;
    rep(cx, 101) {
        rep(cy, 101) {
            ll h = -1;
            rep(i, N) {
                if (H[i] > 0) {
                    h = H[i] + abs(X[i] - cx) + abs(Y[i] - cy);
                    break;
                }
            }

            bool flag2 = false;
            rep(i, N) {
                if (H[i] > 0) {
                    if (h != H[i] + abs(X[i] - cx) + abs(Y[i] - cy)) {
                        flag2 = true;
                        break;
                    }
                }
            }
            if (flag2) continue;

            bool flag3 = false;
            rep(i, N) {
                if (H[i] == 0) {
                    if (!(h >= 1 && (h - abs(X[i] - cx) - abs(Y[i] - cy) <= 0))) {
                        flag3 = true;
                        break;
                    }
                }
            }
            if (flag3) continue;

            cout << cx << " " << cy << " " << h << endl;
            flag = true;
            break;
        }
        if (flag) break;
    }
}