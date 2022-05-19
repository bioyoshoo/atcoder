#include <bits/stdc++.h>
using namespace std;

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N; cin >> N;
    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R.at(i);

    vector<vector<int>> dp(N, vector<int>(2));
    dp[0][0] = 1; dp[0][1] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (R[i] > R[j]) chmax(dp[j][0], dp[i][1] + 1);
            if (R[i] < R[j]) chmax(dp[j][1], dp[i][0] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) chmax(ans, dp[i][j]);
    }
    if (ans < 3) ans = 0;
    cout << ans << endl;
}