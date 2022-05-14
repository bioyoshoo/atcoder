#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<vector<long long>> dp(N, vector<long long>(10, 0));
    dp[0][A[0]] = 1;
    for (int i = 1; i < N; i++) {
        for (int a = 0; a <= 9; a++) {
            dp[i][(a + A[i]) % 10] += dp[i - 1][a];
            dp[i][(a + A[i]) % 10] %= mod;
            
            dp[i][(a * A[i]) % 10] += dp[i - 1][a];
            dp[i][(a * A[i]) % 10] %= mod;
        }
    }

    for (int a = 0; a <= 9; a++) cout << dp[N - 1][a] << endl;
}