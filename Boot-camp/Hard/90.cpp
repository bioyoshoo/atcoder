#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int64_t to;
    int64_t w;
    Edge(int64_t to, int64_t w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

void DFS(const Graph &G, int64_t v, vector<int> &res) {
    if (v == 0) res[0] = 0;

    for (auto e: G[v]) {
        if (res[e.to] != -1) continue;

        if (e.w % 2 == 0) res[e.to] = res[v];
        else if (e.w % 2 == 1) res[e.to] = 1 - res[v];
        DFS(G, e.to, res);
    }
}

int main() {
    int64_t N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }

    vector<int> ans(N, -1);
    DFS(G, 0, ans);

    for (int i = 0; i < N; i++) cout << ans.at(i) << endl;
}