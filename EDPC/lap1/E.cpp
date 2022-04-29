#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e10;
const int64_t V = 1e5;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t N, W;
    cin >> N >> W;
    vector<int64_t> weight(N), value(N);
    for (int i = 0; i < N; i++) cin >> weight.at(i) >> value.at(i);

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(V + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= V; j++) {
            if (j - value[i] >= 0) chmin(dp[i + 1][j], dp[i][j - value[i]] + weight[i]);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

    int64_t ans = 0;
    for (int64_t i = 0; i <= V; i++) if (dp[N][i] <= W) ans = i;
    cout << ans << endl;
}