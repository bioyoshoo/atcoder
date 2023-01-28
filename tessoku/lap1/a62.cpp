#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<bool> seen;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv: G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv);
    }
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    dfs(G, 0);

    bool ans = true;
    rep(x, N) if (!seen[x]) ans = false;

    if (ans) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
}
