#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, H; cin >> N >> H;
    ll a_max = -1;
    vector<ll> B(N);
    rep(i, N) {
        ll a, b; cin >> a >> b;
        a_max = max(a_max, a);
        B[i] = b;
    }
    sort(B.begin(), B.end());
    int it = lower_bound(B.begin(), B.end(), a_max) - B.begin();
    ll ans = 0;
    for (int i = N - 1; i >= it; i--) {
        H -= B[i];
        ans++;
        if (H <= 0) break;
    }
    if (H > 0) ans += (H + a_max - 1)/ a_max;
    cout << ans << endl;
}