#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N, M, K;
int A[300], B[300];

int dp[300][300][15];

// [i, j) の範囲を k 分割
int rec(int i, int j, int k) {
    if (j - i < k) return -1e9;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (k == 1) {
        int cnt = 0;
        rep(x, M) {
            if (i <= A[x] && B[x] < j) cnt += 1;
        }
        return dp[i][j][k] = cnt;
    }
    int res = 0;
    for (int x = i + 1; x <= j - 1; x++) {
        int cand = rec(i, x, 1) + rec(x, j, k - 1);
        res = max(res, cand);
    }
    return dp[i][j][k] = res;
}

int main() {
    cin >> N >> M >> K;
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, 300) rep(j, 300) rep(k, 15) dp[i][j][k] = -1;

    cout << rec(1, N + 1, K) << endl;
}
