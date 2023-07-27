#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int main() {
    int N; cin >> N;
    int dp[31][N];
    rep(i, N) {
        cin >> dp[0][i]; dp[0][i]--;
    }

    rep(i, 30) {
        rep(j, N) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    set<int> st;
    rep(i, N) st.insert(dp[30][i]);

    cout << st.size() << endl;
}
