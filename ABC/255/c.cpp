#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll X, A, D, N; cin >> X >> A >> D >> N;

    if (D < 0) {
        A = A + (N - 1) * D;
        D *= -1;
    }

    ll ans;
    if (X < A) ans = A - X;
    else {
        if (D == 0) ans = abs(X - A);
        else {
            ll m = (X - A) / D + 1;
            if (m >= N) ans = X - (A + (N - 1) * D);
            else ans = min((X - A) % D, D - (X - A) % D);
        }
    }
    cout << ans << endl;
}