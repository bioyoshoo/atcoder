#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    long double a, b, x; cin >> a >> b >> x;

    ld ans;
    if (a*a*b <= 2*x) {
        ans = atan(2*(a*a*b - x) / (a*a*a)) * 180.0 / acos(-1);
    }
    else {
        ans = atan(a*b*b / (2*x)) * 180.0 / acos(-1);
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}