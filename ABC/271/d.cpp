#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, S; cin >> N >> S;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j - A[i] >= 0 && dp[i][j - A[i]]) dp[i + 1][j] = true;
            if (j - B[i] >= 0 && dp[i][j - B[i]]) dp[i + 1][j] = true;
        }
    }

    if (dp[N][S]) cout << "Yes" << endl;
    else cout << "No" << endl;

    if (dp[N][S]) {
        string ans = "";
        int y = S;
        for (int x = N; x >= 1; x--) {
            if (y - A[x - 1] >= 0 && dp[x - 1][y - A[x - 1]]) {
                ans += 'H';
                y -= A[x - 1];
            }
            else if (y - B[x - 1] >= 0 && dp[x - 1][y - B[x - 1]]) {
                ans += 'T';
                y -= B[x - 1];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
