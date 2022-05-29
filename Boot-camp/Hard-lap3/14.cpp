#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n_digits(ll n) {
    return to_string(n).size();
}

int main() {
    ll N; cin >> N;

    int ans = 20;
    for (ll a = 1; a * a <= N; a++) {
        if (N % a != 0) continue;
        ll b = N / a;
        ans = min(ans, n_digits(b));
    }
    cout << ans << endl;
}