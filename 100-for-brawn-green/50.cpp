#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e17;

int N, M;
ll G[20][20];
ll T[20][20];
pair<ll, ll> dp[1LL << 16][20];

// Sの集合内の建物を通り、最後にvを訪れた時の最短経路とその経路数
pair<ll, ll> rec(ll S, int v) {
    if (dp[S][v].first != 0) return dp[S][v];
    if (S == 0) {
        if (v == 0) return {0, 1};
        else return {INF, 0};
    }
    if ((S & (1 << v)) == 0) return {INF, 0};
    
    ll dist = INF, cnt = 0;
    rep(u, N) {
        ll d, w; tie(d, w) = rec(S ^ (1LL << v), u);
        if (d + G[u][v] > T[u][v]) continue;

        if (dist > d + G[u][v]) {
            dist = d + G[u][v]; cnt = w;
        }
        else if (dist == d + G[u][v]) cnt += w;
    }
    return dp[S][v] = {dist, cnt};
}

int main() {
    cin >> N >> M;
    rep(i, N) rep(j, N) G[i][j] = INF;
    rep(i, N) rep(j, N) T[i][j] = 0;

    rep(i, M) {
        int s, t; cin >> s >> t; s--; t--;
        ll d, time; cin >> d >> time;
        G[s][t] = d; G[t][s] = d;
        T[s][t] = time; T[t][s] = time;
    }

    pair<ll, ll> ans = rec((1LL << N) - 1, 0);
    if (ans.first < INF) cout << ans.first << " " << ans.second << endl;
    else cout << "IMPOSSIBLE" << endl;
}
