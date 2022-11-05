#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

int main() {
    int n; cin >> n;
    vector<int> A(n); rep(i, n) cin >> A[i];

    vector<int> dp(n, INF);
    
    rep(i, n) {
        int x = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[x] = A[i];
    }

    int ans = 0;
    rep(i, n) {
        if (dp[i] == INF) break;
        ans = i + 1;
    }
    cout << ans << endl;
}
