#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, D, K; cin >> N >> D >> K;
    vector<pair<ll, ll>> move(D);
    for (int i = 0; i < D; i++) {
        ll l, r; cin >> l >> r;
        move.at(i) = {l, r};
    }
    vector<int> ans(K);
    for (int i = 0; i < K; i++) {
        ll s, t; cin >> s >> t;
        ll pos = s;
        for(int d = 0; d < D; d++) {
            ll l, r;
            tie(l, r) = move[d];
            if (l <= pos && pos <= r) {
                if (l <= t && t <= r) {
                    ans[i] = d + 1;
                    break;
                }
                else if (r < t) pos = r;
                else pos = l;
            }
        }
    }
    for (int i = 0; i < K; i++) cout << ans[i] << endl;
}