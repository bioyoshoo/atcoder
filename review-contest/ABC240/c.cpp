#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool dp[110][10100];

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N), B(N); rep(i, N) cin >> A[i] >> B[i];

    rep(i, 110) rep(j, 10100) dp[i][j] = false;

    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            if (j - A[i] >= 0 && dp[i][j - A[i]]) dp[i + 1][j] = true;
            if (j - B[i] >= 0 && dp[i][j - B[i]]) dp[i + 1][j] = true;
        }
    }

    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
