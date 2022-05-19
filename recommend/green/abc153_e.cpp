#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int H, N; cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N, vector<int>(H + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            if (i + 1 < N) chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i][min(j + A[i], H)], dp[i][j] + B[i]);
        }
    }
    cout << dp[N - 1][H] << endl;
}