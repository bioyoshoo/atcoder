#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n %= 12;
    m %= 60;

    long double s = 360.0 * (long double)n / (long double)12;
    s += 30.0 * (long double)m / 60;
    long double l = 360.0 * (long double)m / (long double)60;
    long double ans = min(abs(l - s), 360 - abs(l - s));

    cout << fixed << setprecision(10);
    cout << ans << endl;
}