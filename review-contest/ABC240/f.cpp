#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int T; cin >> T;

    rep(t, T) {
        int N, M; cin >> N >> M;
        ll B = 0, A = 0;
        ll ans = -1e18;

        rep(i, N) {
            ll x, y; cin >> x >> y;

            // 区間の最初
            ans = max(ans, A + B + x);

            // 区間の間
            if (x < 0 && B > 0) {
                int i = B / abs(x);
                if (i < y) ans = max(ans, A + B*i + x*i*(i + 1)/2);
            }

            // 区間の最後
            A = A + y*B + x*y*(y + 1)/2;
            B = B + y*x;
            ans = max(ans, A);
        }

        cout << ans << endl;
    }
}
