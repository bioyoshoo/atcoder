#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int A[2010];
int dp[2][2010][2010];

int rec(int t, int i, int j) {
    if (i == j) return A[i];
    if (dp[t][i][j] != -1) return dp[t][i][j];

    if (t == 0) {
        dp[t][i][j] = max(rec(1 - t, i + 1, j), rec(1 - t, i, j - 1));
    }
    else if (t == 1) {
        dp[t][i][j] = min(rec(1 - t, i + 1, j), rec(1 - t, i, j - 1));
    }
    return dp[t][i][j];
}

int main() {
    int N; cin >> N;
    rep(i, N) cin >> A[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, N - 1) << endl;
}
