#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;

int V, E;
ll G[20][20], dp[1LL << 16][20];

ll rec(ll S, int v) {
    if (S == 0) {
        if (v == 0) return dp[S][v] = 0;
        else return dp[S][v] = INF;
    }
    if (dp[S][v] != -1) return dp[S][v];
    if ((S & (1LL << v)) == 0)  return dp[S][v] = INF;

    ll res = INF;
    rep(u, V) {
        res = min(res, rec(S ^ (1LL << v), u) + G[u][v]);
    }
    return dp[S][v] = res;
}

int main() {
    cin >> V >> E;
    rep(i, V) rep(j, V) G[i][j] = INF;
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    memset(dp, -1, sizeof(dp));

    ll ans = rec((1LL << V) - 1, 0);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
