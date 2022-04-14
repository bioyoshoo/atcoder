#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H.at(i);

    vector<int> dp(N);
    dp[0] = H[0];
    for (int i = 1; i < N; i++) {
        if (H[i - 1] >= H[i]) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + (H[i] - H[i - 1]);
    }

    cout << dp[N - 1] << endl;
}