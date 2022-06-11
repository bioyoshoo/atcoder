#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e8;

int main() {
    int H, N; cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N + 1, vector<int>(H + 1, INF))
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j )
    }
}