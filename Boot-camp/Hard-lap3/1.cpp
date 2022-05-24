#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[100][100100];

int main() {
    string S; cin >> S;
    int N = S.size();

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') dp[0][i] = i - 1;
        else dp[0][i] = i + 1;
    }
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
    vector<int> ans(N);
    for (int i = 0; i < N; i++) ans[dp[60][i]]++;
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}