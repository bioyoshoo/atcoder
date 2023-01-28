#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, W; cin >> N >> W;
    vector<int> weight(N), value(N);
    rep(i, N) cin >> weight[i] >> value[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {

            // not choose
            chmax(dp[i + 1][j], dp[i][j]);
            
            // choose
            if (j - weight[i] >= 0) {
                chmax(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[N][W] << endl;
}
