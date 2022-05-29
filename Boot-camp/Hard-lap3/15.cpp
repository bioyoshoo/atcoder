#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    ll sum = 0, minus = 0, abs_min = 1e10;
    rep(i, N) {
        ll a; cin >> a;
        if (a < 0) minus++;
        a = abs(a);
        sum += a;
        abs_min = min(abs_min, a);
    }

    ll ans;
    if (minus % 2 == 0) ans = sum;
    else {
        ans = sum - 2 * abs_min;
    }
    cout << ans << endl;
}