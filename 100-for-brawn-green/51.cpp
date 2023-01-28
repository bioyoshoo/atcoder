#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int mod = 10007;

int N;
int dp[1010][10];

int main() {
    cin >> N;
    vector<int> V(N + 1);
    rep(i, N) {
        char c; cin >> c;
        if (c == 'J') V[i + 1] = 0;
        else if (c == 'O') V[i + 1] = 1;
        else if (c == 'I') V[i + 1] = 2;
    }

    dp[0][1] = 1;

    for (int i = 0; i < N; i++) {
        for (int now = 0; now < (1 << 3); now++) {
            for (int nex = 0; nex < (1 << 3); nex++) {
                
                if (i == 0) if (now != 1) continue;

                if ((nex & now) && (nex & (1 << V[i + 1]))) {
                    dp[i + 1][nex] += dp[i][now];
                    dp[i + 1][nex] %= mod;
                }
            }
        }
    }

    int ans = 0;
    rep(i, (1 << 3)) {
        ans += dp[N][i];
        ans %= mod;
    }
    cout << ans << endl;
}
