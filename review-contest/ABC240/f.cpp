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
        ll prev_B_last = 0, prev_C_last = 0;
        ll ans = -1e18;

        rep(i, N) {
            ll a, r; cin >> a >> r;
            
            ll start = prev_B_last + a;
            ll end = start + (r - 1) * a;
            ll sum = (start + end)*r/2;
            ans = max(ans, prev_C_last + sum);

            prev_B_last = end;
            prev_C_last = prev_C_last + sum;
        }

        cout << "!" << ans << "!" << endl;
    }
}