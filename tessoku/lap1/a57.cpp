#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int dp[31][100010];

int main() {
    int N, Q; cin >> N >> Q;
    rep(i, N) {
        cin >> dp[0][i]; dp[0][i]--;
    }

    rep(i, 30) {
        rep(j, N) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    rep(i, Q) {
        int x, y; cin >> x >> y; x--;
        
        rep(j, 31) {
            if (y & (1LL << j)) x = dp[j][x];
        }
        cout << x + 1 << endl;
    }
}
