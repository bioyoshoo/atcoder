#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll x = 1; x * x <= N; x++) ans += N / x;
    for (ll x = 1; x * x <= N; x++) {
        ll L = N / (x + 1), R = N / x;
        ans += x * (R - L);
    }
    cout << ans << endl;
}