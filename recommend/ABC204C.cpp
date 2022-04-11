#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void DFS(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v: G[v]) {
        if (seen[next_v]) continue;
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
    }

    int64_t ans = 0;
    for (int start = 0; start < N; start++) {
        seen.assign(N, false);
        DFS(G, start);
        for (int i = 0; i < N; i++) if (seen[i]) ans++;
    }

    cout << ans << endl;
}