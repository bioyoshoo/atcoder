#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e10;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> H(N);
    for (int i = 0; i < N; i++) cin >> H.at(i);

    vector<int64_t> dp(N, INF);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int k = 1; k <= K; k++) {
            if (i - k < 0) continue;
            chmin(dp[i], dp[i - k] + abs(H[i] - H[i - k]));
        }
    }

    cout << dp[N - 1] << endl;
}