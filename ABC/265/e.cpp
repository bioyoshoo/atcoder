#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    int N, M; cin >> N >> M;
    ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
    vector<ll> S(M), T(M);
    rep(i, M) cin >> S[i] >> T[i];

    ll ans = 1;
    rep(i, N) ans *= 3;

    int sub = 0;
    rep(i, M) {
        int x = S[i], y = T[i];

        for (ll a = 0; a <= N; a++) {
            ll X = D*(x - a*A) - C*(y - a*B);
            ll Y = D*E - C*F;
            if (X % Y != 0 && X / Y < 0) continue;
            
            ll Z = F*(x - a*A) - E*(y - a*B);
            ll W = C*F - D*E;
            if (Z % W != 0 && Z / W < 0) continue;

            sub = 1;
            ll n = a + X / Y + Z / W;
            rep(j, N - n) sub *= 3;
            
            ans -= sub;
        }
    }
    ans -= sub;
    cout << ans << endl;
}