#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int w;
    Edge(int to, int w): to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

vector<int64_t> dist;

void DFS(const Graph &G, int v, int p=-1) {
    for (auto next_e: G[v]) {
        int e_to = next_e.to, e_w = next_e.w;
        if (e_to == p) continue;
        dist[e_to] = dist[v] + e_w;
        DFS(G, e_to, v);
    }
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }

    int Q, K;
    cin >> Q >> K;
    K--;

    dist.assign(N, 0);
    DFS(G, K);

    vector<pair<int, int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        query[i] = {x, y};
    }

    for (int i = 0; i < Q; i++) {
        int x = query[i].first, y = query[i].second;
        cout << dist[x] + dist[y] << endl;
    }
}