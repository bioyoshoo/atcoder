#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> V(N - 1);
    rep(i, N - 1) cin >> V[i];
    int sum;
    cin >> sum;

    ll dp[110][30];
    dp[0][V[0]] = 1;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - V[i] >= 0) dp[i][j] += dp[i - 1][j - V[i]];
            if (j + V[i] <= 20) dp[i][j] += dp[i - 1][j + V[i]];
        }
    }

}