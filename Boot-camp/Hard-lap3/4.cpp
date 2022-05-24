#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll f(ll a, ll x) {
    if (a < 0) return 0;
    return (a + x) / x;
}

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    cout << f(b, x) - f(a - 1, x) << endl;
}