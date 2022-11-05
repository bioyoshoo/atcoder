#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9 + 1;

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    reverse(A.begin(), A.end());

    vector<int> dp(N, INF);
    rep(i, N) {
        int j = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[j] = A[i];
    }

    int ans = 0;
    rep(i, N) {
        if (dp[i] == INF) break;
        ans = i + 1;
    }
    cout << ans << endl;
}
