#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool dp[60][10010];

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N), B(N); rep(i, N) cin >> A[i] >> B[i];

    rep(i, 60) rep(j, 10010) dp[i][j] = false;

    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            if (!dp[i][j]) continue;
            // 遷移
            // i のコインを限界まで使う
            for (int k = 0; k <= B[i]; k++) {
                if (j + k * A[i] > X) break;
                dp[i + 1][j + k * A[i]] = true;
            }
        }
    }

    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
