#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;

    ll ans = 0;
    if (K == 0) ans = N * N;
    else {
        for (ll b = 1; b <= N; b++) {
            ll loop = (N + 1) / b;
            ll x = max(b - K, 0LL) * loop;

            ll r = (N + 1) % b;
            ll y = max(0LL, r - K);
            ans += x + y;
        }
    }
    cout << ans << endl;
}