#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    vector<vector<int>> dp(33, vector<int>(N));
    // 初期position
    for (int i = 0; i < N; i++) dp[0][i] = i;
    // 1step目のpostion
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') dp[1][i] = dp[0][i] + 1;
        else dp[1][i] = dp[0][i] - 1;
    }
    
    for (int step = 2; step < 33; step++) {
        for (int i = 0; i < N; i++) {
            dp[step][i] = dp[step - 1][dp[step - 1][i]];
        }
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) ans[dp[32][i]]++;

    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}