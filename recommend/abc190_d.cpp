#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll res = 0;
    for (ll n = 1; n <= 1e7; n++) {
        if ((2*N - n*n + n) % (2*n) == 0) {
            ll a = (2*N - n*n + n) / (2*n);
            if (a > 0) res += 2;
        }
    }
    cout << res << endl;
}