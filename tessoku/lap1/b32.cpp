#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(K); rep(i, K) cin >> A[i];

    vector<bool> dp(N + 1);

    dp[0] = false;

    for (int i = 0; i <= N; i++) {
        bool flg = false;
        for (int j = 0; j < K; j++) {
            if (i - A[j] >= 0 && !dp[i - A[j]]) {
                dp[i] = true;
                flg = true;
                break;
            }
        }
        if (!flg) dp[i] = false;
    }

    if (dp[N]) cout << "First" << endl;
    else cout << "Second" << endl;
}
