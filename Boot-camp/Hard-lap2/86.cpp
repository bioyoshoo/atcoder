#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1000000007;

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    vector<int> V;
    for (int i = 0; i < N;) {
        if (i + 1 < N && S[i] == S[i + 1]) {
            V.push_back(0);
            i += 2;
        }
        else {
            V.push_back(1);
            i++;
        }
    }
    
    int n = V.size();
    vector<int64_t> dp(n);
    if (V[0] == 0) dp[0] = 6;
    else dp[0] = 3;
    for (int i = 1; i < n; i++) {
        if (V[i - 1] == 0 && V[i] == 0) dp[i] = dp[i - 1] * 3 % mod;
        if (V[i - 1] == 0 && V[i] == 1) dp[i] = dp[i - 1] % mod;
        if (V[i - 1] == 1 && V[i] == 0) dp[i] = dp[i - 1] * 2 % mod;
        if (V[i - 1] == 1 && V[i] == 1) dp[i] = dp[i - 1] * 2 % mod;
    }
    cout << dp[n - 1] << endl;
}