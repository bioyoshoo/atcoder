#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> C(m);
    for (int i = 0; i < m; i++) cin >> C[i];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            chmin(dp[i + 1][j], dp[i][j]);
            if (j - C[i] >= 0) chmin(dp[i + 1][j], dp[i + 1][j - C[i]] + 1);
        }
    }

    cout << dp[m][n] << endl;
}
