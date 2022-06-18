#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<pair<ll, ll>> V(N);
    rep(i, N) cin >> V[i].first >> V[i].second;

    ll ans = N;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            ll p = V[i].first - V[j].first;
            ll q = V[i].second - V[j].second;
            
            ll f = 0;
            rep(s, N) {
                rep(t, N) {
                    ll dx = V[s].first - V[t].first;
                    ll dy = V[s].second - V[t].second;
                    if (dx == p && dy == q) f++;
                }
            }
            ans = min(ans, N - f);
        }
    }
    cout << ans << endl;
}