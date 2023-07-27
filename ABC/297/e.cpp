#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];

    set<ll> st;
    ll dp[N][K + 1];
    rep(i, N) rep(j, K + 1) dp[i][j] = INF;
    rep(i, N) dp[i][0] = 0;
    
    rep(i, N) {
        rep(j, K + 1) {
            if (j + 1 <= K) {
                if (dp[i][j] + A[i] < dp[i][j + 1]) {
                    dp[i][j + 1] = dp[i][j] + A[i];
                    st.insert(dp[i][j + 1]);
                }

                if (i + 1 < N) {
                    if (dp[i][j] + A[i + 1] < dp[i + 1][j + 1]) {
                        dp[i + 1][j + 1] = dp[i][j] + A[i + 1];
                        st.insert(dp[i + 1][j + 1]);
                    }
                }
            }
            if (i + 1 < N) {
                if (dp[i][j] + A[i + 1] < dp[i + 1][j]) {
                    dp[i + 1][j] = dp[i][j] + A[i + 1];
                    st.insert(dp[i + 1][j]);
                }
            }
        }
    }
    
    cout << *st.lower_bound(K) << endl;
}