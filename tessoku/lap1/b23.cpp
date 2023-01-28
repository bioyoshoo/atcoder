#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ld INF = 1e10;

int N;
ld T[15][15], dp[1 << 15][15];

ld rec(int S, int v) {
    // 一番最初にスタート地点にいるか
    if (S == 0) {
        if (v != 0) return INF;
        else return 0;
    }
    // S に v が含まれていない
    if ((S & (1 << v)) == 0) return INF;
    // すでにdpにメモがあるか
    if (dp[S][v] != 0) return dp[S][v];

    ld res = INF;
    rep(u, N) {
        res = min(res, rec(S ^ (1 << v), u) + T[u][v]);
    }

    return dp[S][v] = res;
}

int main() {
    cin >> N;
    vector<ld> X(N), Y(N); rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) rep(j, N) T[i][j] = sqrt((X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]));
    rep(i, N) T[i][i] = INF;

    memset(dp, 0, sizeof(dp));

    cout << fixed << setprecision(12);
    cout << rec((1 << N) - 1, 0) << endl;
}
