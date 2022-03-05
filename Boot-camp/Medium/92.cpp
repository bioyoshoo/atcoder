#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, x;
    cin >> a >> b >> x;

    if (a * b * b == x) cout << 0 << endl;
    else {
        long double theta = atanl(a / (2 * b - 2 * x / (a * a)));
        long double ans = theta * 180 / M_PI;
        cout << fixed << setprecision(10);
        cout << 90 - ans << endl;
    }
}