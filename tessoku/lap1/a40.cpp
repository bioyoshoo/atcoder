#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll C(ll n, ll r) {
    if (n < r) return 0;

    ll X = 1, Y = 1;
    for (int x = n; x >= n - r + 1; x--) X *= x;
    for (int y = r; y >= 1; y--) Y *= y;
    return X / Y;
}

int main() {
    int N; cin >> N;
    map<int, int> mp;
    rep(i, N) {
        int x; cin >> x; mp[x] += 1;
    }

    ll ans = 0;
    for (auto [ignore, v]: mp) {
        ans += C(v, 3);
    }

    cout << ans << endl;
}