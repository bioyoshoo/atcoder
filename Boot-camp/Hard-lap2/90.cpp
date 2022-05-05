#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;

vector<int> ans;
void DFS(const Graph &G, int v, int p = -1, int cur = 0) {
    ans[v] = cur;
    for (auto e: G[v]) {
        if (e.to == p) continue;
        if (e.w % 2 != 0) DFS(G, e.to, v, 1 - cur);
        else DFS(G, e.to, v, cur);
    }
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(Edge(b, w));
        G[b].push_back(Edge(a, w));
    }

    ans.resize(N);
    DFS(G, 0);

    for (auto a: ans) cout << a << endl;
}