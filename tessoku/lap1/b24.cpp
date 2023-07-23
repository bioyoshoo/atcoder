#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> V(N);
    rep(i, N) {
        cin >> V[i].first >> V[i].second;
        V[i].second *= -1;
    }
    sort(V.begin(), V.end());

    vector<int> A;
    rep(i, N) A.push_back(-V[i].second);
    
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    rep(i, N) {
        auto idx = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[idx] = A[i];
    }

    int ans = 0;
    rep(i, N + 1) if (dp[i] < INF) ans = i;
    
    cout << ans << endl;
}
