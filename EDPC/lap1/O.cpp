#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>((1LL << N), 0));
    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (ll S = 0; S < (1LL << N); S++) {
            if (dp[i][S] == 0) continue;
            for (int j = 0; j < N; j++) {
                if ((S & (1LL << j)) == 0 && A[i][j] == 1) {
                    dp[i + 1][S | (1LL << j)] += dp[i][S] % mod;
                    dp[i + 1][S | (1LL << j)] %= mod;
                }
            }
        }
    }
    cout << dp[N][(1LL << N) - 1] << endl;
}