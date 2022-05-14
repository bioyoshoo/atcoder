#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    ll min_R = 1e10, max_L = -1;
    for (int i = 0; i < N; i++) {
        ll l, r; cin >> l >> r;
        min_R = min(min_R, r); max_L = max(max_L, l);
        if (min_R >= max_L) cout << 0 << endl;
        else {
            ll x = min_R + (max_L - min_R) / 2;
            ll ans = max(x - min_R, max_L - x);
            cout << ans << endl;
        }
    }
}