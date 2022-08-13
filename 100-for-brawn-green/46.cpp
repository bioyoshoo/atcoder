#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e15;

ll R[110], C[110];
ll memo[110][110];

ll rec(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    if (j - i <= 1) return 0;
    ll res = INF;
    for (int k = i + 1; k <= j - 1; k++) {
        res = min(res, rec(i, k) + rec(k, j) + R[i]*R[k]*C[j - 1]);
    }
    return memo[i][j] = res;
}

int main() {
    int n; cin >> n;
    rep(i, n) cin >> R[i] >> C[i];

    memset(memo, -1, sizeof(memo));
    cout << rec(0, n) << endl;
}