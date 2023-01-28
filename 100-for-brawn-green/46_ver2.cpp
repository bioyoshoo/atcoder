#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<ll> R, C;
ll memo[110][110];
ll rec(int l, int r) {
    if (l + 1 >= r) return 0;
    if (l + 2 == r) return R[l]*C[l]*C[r - 1];
    if (memo[l][r] != -1) return memo[l][r];

    ll m = 1e18;
    for (int i = l + 1; i < r; i++) {
        m = min(m, rec(l, i) + rec(i, r) + R[l]*C[i - 1]*C[r - 1]);
    }
    return memo[l][r] = m;
}

int main() {
    int n; cin >> n;
    R.resize(n); C.resize(n);
    rep(i, n) cin >> R[i] >> C[i];
    memset(memo, -1, sizeof(memo));

    cout << rec(0, n) << endl;
}
