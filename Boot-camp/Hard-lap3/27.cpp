#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<ll> dp;
void DFS(const Graph &G, int v, int p = -1, ll sum = 0) {
    dp[v] += sum;
    for (auto next_v: G[v]) {
        if (next_v == p) continue;
        DFS(G, next_v, v, dp[v]);
    }
}

int main() {
    ll N, Q; cin >> N >> Q;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dp.assign(N, 0);
    rep(i, Q) {
        int p; cin >> p; p--;
        ll x; cin >> x;
        dp[p] += x;
    }
    DFS(G, 0);
    rep(i, N) cout << dp[i] << endl;
}