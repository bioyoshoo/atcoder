#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e8;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int H, N; cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N + 1, vector<int>(H + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            if (i < N) chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i][min(j + A[i], H)], dp[i][j] + B[i]);
        }
    }

    cout << dp[N][H] << endl;
}