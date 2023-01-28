#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

ld P;
ld f(ld x) {
    return x + P * pow(2, -x/1.5);
}

int main() {
    cin >> P;

    ld l = 0, r = 1e18;
    while (r - l > 1e-9) {
        ld c1 = (2*l + r) / 3;
        ld c2 = (l + 2*r) / 3;

        if (f(c1) > f(c2)) l = c1;
        else r = c2;
    }

    cout << fixed << setprecision(10);
    cout << f(l) << endl;
}