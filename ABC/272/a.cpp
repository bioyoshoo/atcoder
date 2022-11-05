#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n; cin >> n;
    ll ans = 0;
    rep(i, n) {
        int a; cin >> a;
        ans += a;
    }
    cout << ans << endl;
}