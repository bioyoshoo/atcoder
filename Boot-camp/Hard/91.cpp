#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int id;
    Edge(int to, int id): to(to), id(id) {}
};

using Graph = vector<vector<Edge>>;

void DFS(const Graph &G, vector<int> &ans, int v = -1, int p = -1, int c = -1) {
    int color = 1;
    for (auto next_e: G[v]) {
        int e_to = next_e.to, e_id = next_e.id;
        if (e_to == p) continue;
        if (color == c) color++;
        ans[e_id] = color;
        color++;
        DFS(G, ans, e_to, v, ans[e_id]);
    }
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(Edge(b, i));
        G[b].push_back(Edge(a, i));
    }

    vector<int> ans(N - 1, 0);
    DFS(G, ans, 0);

    int max_ans = -1;
    for (int i = 0; i < N - 1; i++) max_ans = max(max_ans, ans[i]);
    cout << max_ans << endl;

    for (int i = 0; i < N - 1; i++) cout << ans[i] << endl;
}