#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main() {
    int N; cin >> N;

    vector<mint> dp(10);
    for (int i = 1; i <= 9; i++) dp[i] = 1;

    for (int i = 1; i < N; i++) {
        vector<mint> dp_new(10);
        for (int j = 1; j <= 9; j++) {
            if (j == 1) dp_new[j] = dp[1] + dp[2];
            else if (j == 9) dp_new[j] = dp[9] + dp[8];
            else dp_new[j] = dp[j - 1] + dp[j] + dp[j + 1]; 
        }
        dp = dp_new;
    }

    mint ans = 0;
    for (int i = 1; i <= 9; i++) ans += dp[i];
    cout << ans.val() << endl;
}
