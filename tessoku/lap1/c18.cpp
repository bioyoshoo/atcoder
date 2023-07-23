#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[410][410];
ll A[410];
// [i, j] の区間の最小値
ll rec(int i, int j) {
    if (j - i + 1 < 2) return 1e18;
    if (j - i + 1 == 2) return abs(A[i] - A[j]);
    if (dp[i][j] != -1) return dp[i][j];
    
    ll res = 1e18;
    for (int k = i; k <= j - 1; k++) {
        res = min(res, rec(i, k) + rec(k + 1, j));
    }
    res = min(res, rec(i + 1, j - 1) + abs(A[i] - A[j]));
    return dp[i][j] = res;
}

int main() {
    int N; cin >> N;
    rep(i, 2*N) cin >> A[i];

    rep(i, 410) rep(j, 410) dp[i][j] = -1;

    cout << rec(0, 2*N - 1) << endl;
}
