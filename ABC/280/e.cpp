#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    ll N, P; cin >> N >> P;

    vector<mint> dp(N + 1);
    mint p2 = (mint)P / 100, p1 = 1 - (mint)P / 100;
    dp[0] = 0; dp[1] = p1;

    for (int i = 2; i <= N; i++) {
        if (i != N) dp[i] = p1 * (dp[i - 1] + 1) + p2 * (dp[i - 2] + 1);
        else dp[i] = (dp[i - 1] + 1) + p2 * (dp[i - 2] + 1);
    }

    cout << dp[N].val() << endl;
}
