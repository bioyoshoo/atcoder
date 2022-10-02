#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int V, E;
int G[20][20];
int dp[100000][20];

int rec(int S, int v) {
    if (dp[S][v] != -1) return dp[S][v];
    if (S == 0) {
        if (v == 0) return dp[S][v] = 0;
        else return dp[S][v] = INF;
    }
    // ここでvがSに含まれているかチェックする
    if ((S & (1 << v)) == 0) return dp[S][v] = INF;

    int dist = INF;
    rep(u, V) {
        chmin(dist, rec(S ^ (1 << v), u) + G[u][v]);
    }
    return dp[S][v] = dist;
}

int main() {
    cin >> V >> E;
    rep(i, V) rep(j, V) G[i][j] = INF;
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    memset(dp, -1, sizeof(dp));

    int ans = rec((1 << V) - 1, 0);
    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}
