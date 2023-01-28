#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N;

ld f(ld x) {
    return x*x*x + x - N;
}
int main() {
    cin >> N;

    ld L = 0, R = 100;
    while (R - L > 0.000001) {
        ld x = (L + R) / 2;

        if (f(x) >= 0) R = x;
        else if (f(x) < 0) L = x;
    }

    cout << fixed << setprecision(6);
    cout << L << endl;
}
