#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        mp[a]++;
    }
    vector<int> V;
    for (auto m: mp) V.push_back(m.second);
    
    int n = V.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(4));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i + 1][j] += dp[i][j];
            if (j > 0) dp[i + 1][j] += V[i] * dp[i][j - 1];
        }
    }
    cout << dp[n][3] << endl;
}