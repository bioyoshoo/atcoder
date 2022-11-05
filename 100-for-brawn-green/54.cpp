#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

int main() {
    int N; cin >> N;
    vector<int> C(N); rep(i, N) cin >> C[i];

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    rep(i, N) {
        int j = lower_bound(dp.begin(), dp.end(), C[i]) - dp.begin();
        dp[j] = C[i];
    }

    int ans = 0;
    rep(i, N + 1) {
        if (dp[i] == INF) break;
        ans = N - i;
    }

    cout << ans << endl;
}
