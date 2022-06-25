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

    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    rep(i, N + 1) {
        int j = 1;
        while (i - 6 * j >= 0) {
            chmin(dp[i], dp[i - 6 * j] + 1);
            j *= 6;
        }
        j = 1;
        while (i - 9 * j >= 0) {
            chmin(dp[i], dp[i - 9 * j] + 1);
            j *= 9;
        }
        chmin(dp[i], dp[i - 1] + 1);
    }
    cout << dp[N] << endl;
}