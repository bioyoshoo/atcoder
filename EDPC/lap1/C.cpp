#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

int main() {
    int64_t N;
    cin >> N;
    vector<vector<int64_t>> happines(N, vector<int64_t>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) cin >> happines[i][j];
    }

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(3, 0));
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < 3; j++) {
            int last1 = (j + 1) % 3, last2 = (j + 2) % 3;
            chmax(dp[i][j], dp[i - 1][last1] + happines[i - 1][last1]);
            chmax(dp[i][j], dp[i - 1][last2] + happines[i - 1][last2]);
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < 3; i++) chmax(ans, dp[N][i]);
    cout << ans << endl;
}