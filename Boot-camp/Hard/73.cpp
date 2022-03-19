#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e15;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;

    vector<int64_t> dp(N + 1, MAX);
    dp[0] = 0;

    for (int i = 1; i < N + 1; i++) {
        int64_t a = 6;
        while (i - a > 0) {
            chmin(dp[i], dp[i - a] + 1);
            a *= 6;
        }
        
        int64_t b = 9;
        while (i - b > 0) {
            chmin(dp[i], dp[i - b] + 1);
            b *= 9;
        }

        chmin(dp[i], dp[i - 1] + 1);
    }

    cout << dp[N] << endl;
}