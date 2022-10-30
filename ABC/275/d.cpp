#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

map<ll, ll> mp;

ll f(ll n) {
    if (n == 0) return 1;
    if (mp.count(n)) return mp[n];
    else {
        ll a = f(n / 2), b = f(n / 3);
        mp[n / 2] = a; mp[n / 3] = b;
        return mp[n] = a + b;
    }
}

int main() {
    ll N; cin >> N;

    cout << f(N) << endl;
}
