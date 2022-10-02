#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

int main() {
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<int> dp(n, INF);

    rep(i, n) {
        int idx = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[idx] = A[i];
    }

    int ans = -1;
    rep(i, n) if (dp[i] != INF) ans = i + 1;
    cout << ans << endl;
}
