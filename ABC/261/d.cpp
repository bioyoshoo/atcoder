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
    int N, M; cin >> N >> M;
    vector<ll> X(N), C(N + 1);
    rep(i, N) cin >> X[i];
    rep(i, M) {
        int c; ll y; cin >> c >> y;
        C[c] = y;
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) { 
            chmax(dp[i + 1][0], dp[i][j] + C[0]);
            chmax(dp[i + 1][j + 1], dp[i][j] + X[i] + C[j + 1]);
        }
    }

    ll ans = 0;
    rep(cnt, N + 1) ans = max(ans, dp[N][cnt]);
    cout << ans << endl;
}