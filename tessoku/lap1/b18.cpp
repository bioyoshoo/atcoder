#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool dp[65][10010];

int main() {
    int N, S; cin >> N >> S;
    vector<int> A(N); rep(i, N) cin >> A[i];

    rep(i, 65) rep(j, 10010) dp[i][j] = false;
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (dp[i][j]) dp[i + 1][j] = true;
            if (j - A[i] >= 0 && dp[i][j - A[i]]) dp[i + 1][j] = true;
        }
    }

    if (!dp[N][S]) cout << -1 << endl;
    else {
        vector<int> ans;
        int x = N, y = S;
        while (x > 0) {
            if (dp[x - 1][y]) x--;
            else if (dp[x - 1][y - A[x - 1]]) {
                ans.push_back(x);
                y -= A[x - 1];
                x--;
            }
        }
        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for (auto a: ans) cout << a << " ";
        cout << endl;
    }
}
