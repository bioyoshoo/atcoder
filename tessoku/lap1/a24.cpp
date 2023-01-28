#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    rep(i, N) {
        int idx = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[idx] = A[i];
    }

    int ans = -1;
    rep(i, N + 1) if (dp[i] != INF) ans = i;

    cout << ans << endl;
}
