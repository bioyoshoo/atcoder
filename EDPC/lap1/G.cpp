#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int64_t> dp;
int64_t rec(const Graph &G, int v) {
    if (dp[v] != -1) return dp[v];
    if (G[v].size() == 0) return dp[v] = 0;
    int64_t max_d = -1;
    for (auto next_e: G[v]) {
        max_d = max(max_d, rec(G, next_e) + 1);
    }
    return dp[v] = max_d;
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y);
    }

    dp.assign(N, -1);
    for (int s = 0; s < N; s++) {
        if (dp[s] != -1) continue;
        rec(G, s);
    }

    int64_t ans = -1;
    for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}