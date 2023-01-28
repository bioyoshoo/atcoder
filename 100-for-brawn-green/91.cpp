#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ld pi = acos(-1);

int main() {
    ld a, b, x; cin >> a >> b >> x;

    ld ans;
    if (a*a*b < 2*x) ans = atan(2*(a*a*b - x) / (a*a*a));
    else ans = atan(a*b*b / (2*x));
    ans = ans / pi * 180;

    cout << fixed << setprecision(10);
    cout << ans << endl;
}