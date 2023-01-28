#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e8;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 1; i < N; i++) cin >> A[i];
    for (int i = 2; i < N; i++) cin >> B[i];

    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        if (i > 0) chmin(dp[i], dp[i - 1] + A[i]);
        if (i > 1) chmin(dp[i], dp[i - 2] + B[i]);
    }

    vector<int> ans;
    int x = N - 1;

    while (x >= 0) {
        ans.push_back(x);

        if ((x > 1) && (dp[x] == dp[x - 2] + B[x])) x -= 2;
        else x -= 1;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto a: ans) cout << a + 1 << " ";
    cout << endl;
}
