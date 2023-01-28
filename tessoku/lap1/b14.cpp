#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[i][j]) dp[i + 1][j] = true;
            if (j - A[i] >= 0 && dp[i][j - A[i]]) dp[i + 1][j] = true;
        }
    }

    if (dp[N][K]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
