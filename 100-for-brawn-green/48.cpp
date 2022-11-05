#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, A[310], dp[310][310];

ll rec(int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if ((abs(A[i] - A[j-1]) <= 1) && (rec(i+1, j-1) == j-i-2)) {
        return dp[i][j] = j-i;
    }

    ll res = 0;
    for (int x = i+1; x <= j-1; x++) {
        res = max(res, rec(i, x) + rec(x, j));
    }
    return dp[i][j] = res;
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;

        rep(i, n) cin >> A[i];
        memset(dp, -1, sizeof(dp));

        cout << rec(0, n) << endl;
    }
}
