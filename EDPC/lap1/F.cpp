#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

int main() {
    string S, T;
    cin >> S >> T;

    int n = S.size(), m = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i - 1] == T[j - 1]) chmax(dp[i][j], dp[i - 1][j - 1] + 1);
            else {
                chmax(dp[i][j], dp[i - 1][j]);
                chmax(dp[i][j], dp[i][j - 1]);
            }
        } 
    }

    vector<bool> ans(n, false);
    int len = dp[n][m];
    int i = n, j = m;
    while (len > 0) {
        if (S[i - 1] == T[j - 1]) {
            ans[i - 1] = true;
            i--;
            j--;
            len--;
        }
        else if (dp[i][j] == dp[i - 1][j]) i--;
        else j--;
    }
    for (int i = 0; i < n; i++) if (ans[i]) cout << S[i];
    cout << endl;
}
