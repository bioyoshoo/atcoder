#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

    ll ans = 1e15;
    for (ll ab = 0; ab <= 2 * max(X, Y); ab += 2) {
        ll cand = C * ab;

        ll a = X - ab / 2;
        ll b = Y - ab / 2;
        if (a > 0) cand += A * a;
        if (b > 0) cand += B * b;

        ans = min(cand, ans);
    }
    cout << ans << endl;
}