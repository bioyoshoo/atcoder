#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;

vector<long long> depth;
void DFS(const Graph &G, int v, int p = -1, long long d = 0) {
    depth[v] = d;
    for (auto e: G[v]) {
        if (e.to == p) continue;
        DFS(G, e.to, v, d + e.w);
    }
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(Edge(b, w));
        G[b].push_back(Edge(a, w));
    }
    
    int Q, K; cin >> Q >> K; K--;
    depth.resize(N);
    DFS(G, K);
    vector<long long> ans(Q);
    for (int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y; x--; y--;
        ans[i] = depth[x] + depth[y];
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << endl;
}