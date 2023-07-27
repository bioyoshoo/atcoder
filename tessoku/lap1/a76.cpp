#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

mint dp[200000], sum[200000];

int main() {
    int N, W, L, R; cin >> N >> W >> L >> R;
    vector<int> X(N + 2); rep(i, N) cin >> X[i + 1];
    X[0] = 0; X[N + 1] = W;
    
    dp[0] = 1; sum[0] = 1;
    for (int i = 1; i <= N + 1; i++) {
        int posL = lower_bound(X.begin(), X.end(), X[i] - R) - X.begin();
        int posR = lower_bound(X.begin(), X.end(), X[i] - L + 1) - X.begin(); posR--;

        if (posR != -1) dp[i] += sum[posR];
        if (posL >= 1) dp[i] -= sum[posL - 1];

        sum[i] = dp[i] + sum[i - 1];
    }

    cout << dp[N + 1].val() << endl;
}
