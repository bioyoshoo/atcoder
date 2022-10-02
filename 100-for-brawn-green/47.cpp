#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N;
ll dp[2010][2010];
vector<ll> A;

ll rec(int i, int j, int s) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) {
        if (s == 0) return A[i];
        else return 0;
    }
    if (s == 0) {
        return dp[i][j] = max(rec((i + 1) % N, j, 1) + A[i], rec(i, (j - 1 + N) % N, 1) + A[j]);
    }
    else {
        if (A[i] > A[j]) return dp[i][j] = rec((i + 1) % N, j, 0);
        else return dp[i][j] = rec(i, (j - 1 + N) % N, 0);
    }
}

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    memset(dp, -1, sizeof(dp));

    ll ans = -1;
    rep(i, N) ans = max(ans, rec((i + 1) % N, (i - 1 + N) % N, 1) + A[i]);

    cout << ans << endl;
}
