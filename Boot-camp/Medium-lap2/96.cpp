#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    set<int> A;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }

    vector<int64_t> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        if (i + 1 <= N && !A.count(i + 1)) {
            dp[i + 1] += dp[i] % mod;
            dp[i + 1] %= mod;
        }
        if (i + 2 <= N && !A.count(i + 2)) {
            dp[i + 2] += dp[i] % mod;
            dp[i + 2] %= mod;
        }
    }

    cout << dp[N] << endl;
}