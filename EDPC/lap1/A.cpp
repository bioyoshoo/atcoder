#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e10;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> H(N);
    for (int i = 0; i < N; i++) cin >> H.at(i);

    vector<int64_t> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i + 2 < N) chmin(dp[i + 2], dp[i] + abs(H[i] - H[i + 2]));
        if (i + 1 < N) chmin(dp[i + 1], dp[i] + abs(H[i] - H[i + 1]));
    }

    cout << dp[N - 1] << endl;
}