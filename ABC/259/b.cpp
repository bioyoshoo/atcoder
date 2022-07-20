#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ld PI = acos(-1);

int main() {
    ld a, b; cin >> a >> b;
    ld d; cin >> d;

    ld rad = d * PI / 180;

    ld x = cos(rad) * a - sin(rad) * b;
    ld y = sin(rad) * a + cos(rad) * b;

    cout << fixed << setprecision(12);
    cout << x << " " << y << endl;
}