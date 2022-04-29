#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

int main() {
    int64_t N, W;
    cin >> N >> W;
    vector<int64_t> weight(N), value(N);
    for (int i = 0; i < N; i++) cin >> weight.at(i) >> value.at(i);

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(W + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - weight[i] >= 0) chmax(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);
            chmax(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << dp[N][W] << endl;
}