#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

ll A[500];
ll dp[500][500];
ll rec(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return 0;
    ll cost = 1e15;
    for (int i = l; i < r; i++) chmin(cost, rec(l, i) + rec(i + 1, r));
    ll sum = A[r];
    if (l > 0) sum -= A[l - 1];
    return dp[l][r] = cost + sum;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) A[i + 1] += A[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, N - 1) << endl;
}