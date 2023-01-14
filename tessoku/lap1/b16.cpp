#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int MAX = 1e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int dp[100010];

int main() {
    int N; cin >> N;
    vector<int> H(N); rep(i, N) cin >> H[i];
    rep(i, 100010) dp[i] = MAX;

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0) chmin(dp[i], dp[i - 1] + abs(H[i] - H[i - 1]));
        if (i > 1) chmin(dp[i], dp[i - 2] + abs(H[i] - H[i - 2]));
    }

    cout << dp[N - 1] << endl;
}
