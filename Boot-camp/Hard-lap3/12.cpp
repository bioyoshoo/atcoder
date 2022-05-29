#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    ll N; cin >> N;
    vector<ll> D(N), cnt(N - 1);
    ll depth = -1;
    rep(i, N) {
        ll d; cin >> d;
        depth = max(depth, d);
        D[i] = d;
        cnt[d]++;
    }

    ll ans = 0;
    if (D[0] == 0 && cnt[0] == 1) {
        mint dp[100100];
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            if (cnt[i] == 0 || cnt[i + 1] == 0) dp[i + 1] = 0;
            else {
                mint path = 1;
                rep(r, cnt[i + 1]) path *= cnt[i];
                dp[i + 1] = dp[i] * path;
            }
        }
        ans = dp[depth].val();
    }
    cout << ans << endl;
}