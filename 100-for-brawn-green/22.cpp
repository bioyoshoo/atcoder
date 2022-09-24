#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

ld P;

ld f(ld x) {
    return x + P * pow(2, (-x/1.5));
}

ld fd(ld x) {
    return 1 + P * pow(2, -x/1.5) * log(pow(2, -1/1.5));
}

int main() {
    cin >> P;

    ld l = 0, r = 1e18;
    while (r - l > 1e-9) {
        ld mid = (l + r) / 2;

        if (fd(mid) < 0) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(10);
    cout << f(l) << endl;
}
