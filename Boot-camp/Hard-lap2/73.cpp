#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e10;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i <= N; i++) {
        if (i + 1 <= N) chmin(dp[i + 1], dp[i] + 1);
        int64_t a = 6;
        while (i + a <= N) {
            chmin(dp[i + a], dp[i] + 1);
            a *= 6;
        }
        int64_t b = 9;
        while (i + b <= N) {
            chmin(dp[i + b], dp[i] + 1);
            b *= 9;
        }
    }

    cout << dp[N] << endl;
}