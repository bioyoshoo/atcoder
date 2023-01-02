#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll a, b; cin >> a >> b;

    ll ans = 1;
    rep(i, b) ans *= a;

    cout << ans << endl;
}