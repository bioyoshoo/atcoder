#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> dist;
void BFS(const Graph &G, int s=0) {
    dist[s] = 0;
    queue<int> todo;
    todo.push(s);
    while (!todo.empty()) {
        int v = todo.front();
        todo.pop();
        for (auto v2: G[v]) {
            if (dist[v2] != -1) continue;
            dist[v2] = dist[v] + 1;
            todo.push(v2);
        }
    }
}

int main() {
    int n; cin >> n;
    Graph G(n);
    rep(i, n) {
        int u, k; cin >> u >> k; u--;
        rep(j, k) {
            int v; cin >> v; v--;
            G[u].push_back(v);
        }
    }

    dist.assign(n, -1);
    BFS(G);

    rep(i, n) cout << i + 1 << " " << dist[i] << endl;
}