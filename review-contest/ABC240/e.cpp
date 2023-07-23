#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<pair<int, int>> dp;
void DFS(const Graph &G, int v, int p, int &cnt) {
    int L = 1e9, R = -1;
    for (auto nv: G[v]) {
        if (nv == p) continue;
        DFS(G, nv, v, cnt);
        L = min(L, dp[nv].first);
        R = max(R, dp[nv].second);
    }

    if (L != 1e9) {
        dp[v] = make_pair(L, R);
    }
    else {
        dp[v] = make_pair(cnt, cnt);
        cnt += 1;
    }
    return;
}

int main() {
    int N; cin >> N;
    Graph G(N);
    rep(i, N - 1) {
        int u, v; cin >> u >> v; u--; v--; 
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dp.resize(N);

    int cnt = 1;
    DFS(G, 0, -1, cnt);

    rep(i, N) {
        cout << dp[i].first << " " << dp[i].second << endl;
    }
}
