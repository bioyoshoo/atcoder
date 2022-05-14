#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n, ll k) {
    ll res = 0;
    for (int i = 60; i >= 0; i--) {
        if (n & (1LL << i)) {
            ll upper = (1LL << (i + 1)) - 1;
            ll lower = (1LL << i);
            if (upper < k) res += upper - lower + 1;
            else if (lower <= k && k <= upper) res += k - lower + 1;
        }
    }
    return res;
}

int main() {
    ll N, L, R;
    cin >> N >> L >> R;

    cout << f(N, R) - f(N, L - 1) << endl;
}