#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        vector<ll> cumsum = dp[i];
        for (int r = 1; r <= K; r++) {
            cumsum[r] += cumsum[r - 1] % mod;
            cumsum[r] %= mod;
        }
        
        for (int k = 0; k <= K; k++) {
            if (k - A[i] - 1 >= 0) dp[i + 1][k] = cumsum[k] - cumsum[k - A[i] - 1];
            else dp[i + 1][k] = dp[i + 1][k] = cumsum[k];
            if (dp[i + 1][k] < 0) dp[i + 1][k] += mod;
        }
    }
    cout << dp[N][K] << endl;
}