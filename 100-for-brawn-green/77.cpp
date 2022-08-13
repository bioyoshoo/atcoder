#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e5;

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> dist(n);
    for (int i = 1; i < n; i++) cin >> dist[i];
    for (int i = 1; i < n; i++) dist[i] += dist[i - 1];

    ll ans = 0;
    int now = 0;
    rep(i, k) {
        int a; cin >> a;
        int nex = now + a;
        ans += abs(dist[nex] - dist[now]);
        ans %= mod;
        now = nex;
    }
    cout << ans << endl;
}