#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N; cin >> N;

    bool flag = false;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll x = N * h * n, y = 4 * h * n - N * n - N * h;
            if (y != 0 && x % y == 0) {
                ll w = x / y;
                if (1 <= w && w <= 3500) {
                    cout << h << " " << n << " " << w << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
    }
}