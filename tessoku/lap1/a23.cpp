#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 10000;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M);
    rep(i, M) {
        int state = 0;
        rep(j, N) {
            int a; cin >> a;
            if (a == 1) state += (1 << j);
        }
        A[i] = state;
    }

    vector<vector<int>> dp(M + 1, vector<int>(1 << N, INF));
    dp[0][0] = 0;

    rep(i, M) {
        rep(S, 1 << N) {

            if (dp[i][S] == INF) continue;

            // use
            chmin(dp[i + 1][S | A[i]], dp[i][S] + 1);

            // do not use
            chmin(dp[i + 1][S], dp[i][S]);
        }
    }

    if (dp[M][(1 << N) - 1] == INF) cout << -1 << endl;
    else cout << dp[M][(1 << N) - 1] << endl;
}
