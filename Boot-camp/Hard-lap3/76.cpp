#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll S; cin >> S;
    int N = to_string(S).size();

    ll ans = 0;
    for (ll i = 0; i < (1LL << (N - 1)); i++) {
        ll T = S;
        ll d = 10;
        rep(j, N - 1) {
            if (i & (1LL << j)) {
                ans += T % d;
                T /= d;
                d = 10;
            }
            else d *= 10;
        }
        ans += T;
    }
    cout << ans << endl;
}