#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G, int v) {
    int n = G.size();
    vector<int> seen(n, -1);
    seen[v] = 0;
    queue<int> todo;
    todo.push(v);

    while (!todo.empty()) {
        int top = todo.front();
        todo.pop();
        for (auto next_v: G[top]) {
            if (seen[next_v] != -1) continue;
            seen[next_v] = seen[top] + 1;
            todo.push(next_v);
        }
    }
    return seen;
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }
    G[X].push_back(Y);
    G[Y].push_back(X);

    vector<int> ans(N, 0);
    for (int start = 0; start < N; start++) {
        vector<int> depth = BFS(G, start);
        for (int i = 0; i < N; i++) ans[depth[i]]++;
    }

    for (int i = 1; i < N; i++) cout << ans[i] / 2 << endl;
}