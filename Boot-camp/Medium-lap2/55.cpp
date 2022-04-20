#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> seen;
void DFS(const Graph &G, int v = 0) {
    if (v == 0) seen[v] = 0;

    for (int next_v: G[v]) {
        if (seen[next_v] != -1) continue;
        seen[next_v] = seen[v] + 1;
        if (seen[next_v] == 2) continue;
        DFS(G, next_v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, -1);
    DFS(G, 0);

    if (seen[N - 1] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}