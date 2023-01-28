#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int P[2100], A[2100];
int dp[2100][2100];

int rec(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int cand1 = rec(i + 1, j);
    int cand2 = rec(i, j - 1);

    if (i <= P[i] && P[i] < j) cand1 += A[i];
    if (i <= P[j - 1] && P[j - 1] < j) cand2 += A[j - 1];

    return dp[i][j] = max(cand1, cand2);
}

int main() {
    int N; cin >> N;
    rep(i, N) {
        cin >> P[i] >> A[i]; P[i]--;
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(0, N) << endl;
}
