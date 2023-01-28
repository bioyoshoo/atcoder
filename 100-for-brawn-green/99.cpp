#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int M; cin >> M;
    vector<ll> D(M), C(M);
    rep(i, M) cin >> D[i] >> C[i];

    ll ans = 0, sum = 0;
    rep(i, M) {
        sum += D[i] * C[i];
        ans += C[i] - 1;
    }
    ans += M - 1;


    while (sum > 10) {
        int a = sum % 10;
        int b = (sum % 100 - a) / 10;
        sum = sum / 100 * 100 + (a + b);
        ans++;
    }

    cout << ans << endl;
}