#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    long double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    long double ans = abs((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa)) / 2;
    cout << fixed << setprecision(10);
    cout << ans << endl;
}