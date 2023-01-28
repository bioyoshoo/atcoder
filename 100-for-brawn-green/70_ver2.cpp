#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    ll m, n; cin >> m >> n;

    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * m % mod;
        m = m * m % mod;
        n >>= 1;
    }

    cout << res << endl;
}
