#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    string S; cin >> S;
    int N = S.size();
    S = ' ' + S;

    vector<vector<int>> dp(N + 1, vector<int>(2, -1));
    dp[0][0] = 0;
    rep(i, N + 1) {
        rep(j, 2) {
            if (dp[i][j] == -1) continue;
            if (i + 1 <= N) {
                // 1文字が連続する場合 1 -> 1
                if (j == 0 && S[i + 1] != S[i]) chmax(dp[i + 1][0], dp[i][j] + 1);
                // 2 -> 1
                else if (j == 1) chmax(dp[i + 1][0], dp[i][j] + 1);
            }
            // 2 -> 1 or 2 -> 2
            if (i + 2 <= N) chmax(dp[i + 2][1], dp[i][j] + 1);
        }
    }
    cout << max(dp[N][0], dp[N][1]) << endl;
}