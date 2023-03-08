#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll divisors(ll n) {
    ll res = 0;
    for (ll a = 1; a*a <= n; a++) {
        if (n % a == 0) {
            if (a*a == n) res++;
            else res += 2;
        }
    }
    return res;
}

int main() {
    ll N; cin >> N;
    ll ans = 0;

    for (ll ab = 1; ab < N; ab++) {
        ll cd = N - ab;

        ans += divisors(ab) * divisors(cd);
    }

    cout << ans << endl;
}