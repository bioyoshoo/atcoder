#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<ll> A;
ll dp[3100][3100];
ll rec(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i > j) return 0;
    if (i == j) return dp[i][j] = 0;

    int diff = N - (j - i);
    if (diff % 2 == 0) {
        dp[i][j] = max(rec(i + 1, j) + A[i], rec(i, j - 1) + A[j - 1]);
    }
    else {
        dp[i][j] = min(rec(i + 1, j) - A[i], rec(i, j - 1) - A[j - 1]);
    }
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, N) << endl;
}