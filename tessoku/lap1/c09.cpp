#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[500010][2];

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    
    rep(i, 500010) rep(j, 2) dp[i][j] = 0;

    for (int i = 0; i < N; i++) {
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + A[i]);
        dp[i + 1][1] = dp[i][0];
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
}
