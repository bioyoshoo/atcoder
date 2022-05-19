#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0l i < (n); i++)
using ll = long long;
using mint = modint998244353;

mint sum(ll x) {
    return mint(1 + x) * x / 2;
}

int main() {
    ll N; cin >> N;

    ll l = 1;
    mint ans = 0;
    while (l <= N) {
        ll r = min(N + 1, 10 * l);
        ll len = r - l;
        ans += sum(len);
        l *= 10;
    }
    cout << ans.val() << endl;
}