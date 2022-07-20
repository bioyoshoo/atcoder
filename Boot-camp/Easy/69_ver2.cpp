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

    vector<vector<int>> dp(N + 1, vector<int>(2, -1));
    dp[0][0] = 0; dp[0][1] = 0;
    rep(i, N + 1) {
        rep(j, 2) {
            if (i == 0) chmax(dp[i + 1][0], dp[i][j] + 1);
            if (i + 2 <= N && dp[i][j] != -1) chmax(dp[i + 2][1], dp[i][j] + 1);
            if (i + 1 <= N && S[i] != S[i - 1] && dp[i][j] != -1) chmax(dp[i + 1][0], dp[i][j] + 1);
        }
    }
    cout << max(dp[N][0], dp[N][1]) << endl;
}