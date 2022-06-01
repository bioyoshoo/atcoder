#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    ll a_max = -1, a_gcd;
    vector<ll> A(N);
    rep(i, N) {
        ll a; cin >> a;
        a_max = max(a_max, a);
        if (i == 0) a_gcd = a;
        else a_gcd = gcd(a_gcd, a);
    }

    bool ans;
    if (a_max < K) ans = false;
    else {
        if (a_gcd == 1) ans = true;
        else if (K % a_gcd == 0) ans = true;
        else ans = false;
    }
    if (ans) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}