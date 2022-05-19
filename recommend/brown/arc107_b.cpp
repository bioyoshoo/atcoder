#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;

    ll ans = 0;
    for (ll n = 2; n <= 2 * N; n++) {
        ll m = n - K;
        if (!(2 <= m && m <= 2 * N)) continue;
        ll R1 = min(n - 2, N - 1), L1 = max(n - N - 1, 0LL);
        ll R2 = min(m - 2, N - 1), L2 = max(m - N - 1, 0LL);
        ans += max(0LL, R1 - L1 + 1) * max(0LL, R2 - L2 + 1);
    }
    cout << ans << endl;
}