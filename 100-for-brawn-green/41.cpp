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
    int D, N; cin >> D >> N;
    vector<int> T(D); rep(i, D) cin >> T[i];
    vector<int> A(N), B(N), C(N); rep(i, N) cin >> A[i] >> B[i] >> C[i];

    vector<vector<int>> dp(D, vector<int>(N));
    
    for (int i = 1; i < D; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                // day i -> j, day i - 1 -> k
                if ((T[i] < A[j]) || (B[j] < T[i])) continue;
                if ((T[i - 1] < A[k]) || (B[k] < T[i - 1])) continue;

                chmax(dp[i][j], dp[i - 1][k] + abs(C[j] - C[k]));
            }
        }
    }
    
    int ans = -1;
    rep(i, N) chmax(ans, dp[D - 1][i]);

    cout << ans << endl;
}