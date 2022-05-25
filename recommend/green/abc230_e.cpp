#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N;
    cin >> N;

    ll k;
    for (ll i = 1; i <= N; i++) {
        if (i * i <= N) k = i;
        else break;
    }

    ll ans = 0;
    for (ll n = 1; n <= N / (k + 1); n++) ans += N / n;
    for (ll x = 1; x <= k; x++) {
        ll L = N / (x + 1), R = N / x;
        ans += x * (R - L);
    }
    cout << ans << endl;
}