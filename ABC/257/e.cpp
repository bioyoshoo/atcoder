#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<ll> C(9);
    rep(i, 9) cin >> C[i];

    vector<ll> dp(N + 1);
    dp[0] = 0;
    rep(i, N + 1) {
        rep(j, 9) {
            if (i + C[j] <= N) chmax(dp[i + C[j]], 10 * dp[i] + j + 1);
        }
    }
    ll ans = -1;
    rep(i, N + 1) chmax(ans, dp[i]);
    cout << ans << endl;
}