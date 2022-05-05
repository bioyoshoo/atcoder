#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int id;
    Edge(int to, int id) : to(to), id(id) {};
};
using Graph = vector<vector<Edge>>;

vector<int> ans;
void DFS(const Graph &G, int v, int p = -1, int c = -1) {
    int color = 1;
    for (auto e: G[v]) {
        if (e.to == p) continue;
        if (color == c) color++;
        ans[e.id] = color;
        DFS(G, e.to, v, color);
        color++;
    }
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(Edge(b, i));
        G[b].push_back(Edge(a, i));
    }
    ans.resize(N - 1);
    DFS(G, 0);
    int K = -1;
    for (auto a: ans) K = max(K, a);
    cout << K << endl;
    for (auto a: ans) cout << a << endl;
}