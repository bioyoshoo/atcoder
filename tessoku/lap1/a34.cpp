#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X, Y; cin >> N >> X >> Y;
    int MAX = -1;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i]; MAX = max(MAX, A[i]);
    }

    vector<int> dp(MAX + 1);

    rep(i, MAX + 1) {
        vector<bool> G = {true, true, true};
        if (i - X >= 0) G[dp[i - X]] = false;
        if (i - Y >= 0) G[dp[i - Y]] = false;

        rep(j, 3) {
            if (G[j]) {
                dp[i] = j; break;
            }
        }
    }

    ll sum = 0;
    rep(i, N) sum ^= dp[A[i]];

    if (sum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}
