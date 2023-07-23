#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();

    vector<ll> T(N);
    rep(i, N) T[i] = 1LL * (S[i] - 'A') + 1;

    ll power = 1;
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans += T[i] * power;
        power *= 26;
    }

    cout << ans << endl;
}
