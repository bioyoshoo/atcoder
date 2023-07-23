#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<pair<int, int>> V(N);
    int max_d = -1;
    rep(i, N) {
        int t, d; cin >> t >> d; V[i] = make_pair(d, t);
        max_d = max(max_d, d);
    }
    sort(V.begin(), V.end());

    vector<vector<int>> dp(N + 1, vector<int>(max_d + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        int t, d; tie(d, t) = V[i];
        for (int j = 0; j <= max_d; j++) {
            if (j > d) continue;
            
            chmax(dp[i + 1][j], dp[i][j]);
            if (t <= j) chmax(dp[i + 1][j], dp[i][j - t] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= max_d; i++) ans = max(ans, dp[N][i]);
    cout << ans << endl;
}
