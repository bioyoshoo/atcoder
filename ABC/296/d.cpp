#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M; cin >> N >> M;
    
    ll c = 1;
    while (c*c < M) c++;

    ll ans = 1e18;
    for (ll a = 1; a <= min(c, N); a++) {
        ll b = (M + a - 1) / a;
        if (1 <= b && b <= N) {
            ans = min(ans, 1LL*a*b);
        }
    }

    if (ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;
}
