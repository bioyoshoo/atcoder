#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, x;
    cin >> a >> b >> x;

    long double ans;
    if (2 * x < a * b * b) {
        ans = M_PI / 2 - atan(2 * x / (a * b * b));
    }
    else {
        ans = atan(2LL * (x - a * a * b) / (a * a * a));
    }
    ans *= 180 / M_PI;
    cout << fixed << setprecision(12);
    cout << ans << endl;
}