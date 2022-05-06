#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> depth;
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto next_v: G[v]) {
        if (next_v == p) continue;
        dfs(G, next_v, v, d + 1);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    depth.assign(N, -1);
    dfs(G, 0);

    vector<string> ans(Q);
    for (int i = 0; i < Q; i++) {
        int c, d; cin >> c >> d; c--; d--;
        int dist = depth[c] + depth[d];
        if (dist % 2 == 0) ans.at(i) = "Town";
        else ans.at(i) = "Road";
    }

    for (int i = 0; i < Q; i++) cout << ans[i] << endl;
}