#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll X, Y, A, B; cin >> X >> Y >> A >> B;

    long double x = B / (A - 1);
    ll power = X;
    ll ans = 0;
    while (power <= x && A * power < Y) {
        power = A * power;
        ans++;
    }
    ans += (Y - power - 1) / B;
    cout << ans << endl;
}