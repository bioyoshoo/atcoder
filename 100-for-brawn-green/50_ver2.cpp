#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

int N, M;
ll D[17][17], T[17][17], dp1[1LL << 17][17], dp2[1LL << 17][17];

pair<ll, ll> rec(ll S, int v) {
    if (S == 0) {
        if (v == 0) return {0, 1};
        else return {INF, 0};
    }
    if ((S & (1LL << v)) == 0) return {INF, 0};
    if (dp1[S][v] != -1) return {dp1[S][v], dp2[S][v]};
    
    ll dist = INF, path = 0;
    rep(u, N) {
        ll d, p;
        tie(d, p) = rec(S ^ (1LL << v), u);

        if (d + D[u][v] > T[u][v]) continue;

        if (dist > d + D[u][v]) {
            dist = d + D[u][v]; path = p;
        }
        else if (dist == d + D[u][v]) {
            path += p;
        }
    }
    dp1[S][v] = dist; dp2[S][v] = path;
    return {dist, path};
}

int main() {
    cin >> N >> M;
    rep(i, N) rep(j, N) {
        D[i][j] = INF;
        T[i][j] = 0;
    }
    rep(i, M) {
        ll s, t, d, time; cin >> s >> t >> d >> time; s--; t--;
        D[s][t] = D[t][s] = d; T[s][t] = T[t][s] = time;
    }
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, 0, sizeof(dp1));

    pair<ll, ll> ans = rec((1LL << N) - 1, 0);
    if (ans.first == INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans.first << " " << ans.second << endl;
}
