#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> seen;
void BFS(const Graph &G, int v) {
    seen[v] = 0;
    queue<int> todo;
    todo.push(v);
    while (!todo.empty()) {
        int w = todo.front();
        todo.pop();
        for (auto next_v: G[w]) {
            if (seen[next_v] != -1) continue;
            seen[next_v] = seen[w] + 1;
            todo.push(next_v);
        }
    }
}

int main() {
    int N; cin >> N;
    int x, y; cin >> x >> y; x--; y--;
    
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);

    vector<int> cnt(N - 1);
    for (int s = 0; s < N; s++) {
        seen.assign(N, -1);
        BFS(G, s);
        for (int i = 0; i < N; i++) {
            int d = seen[i];
            if (d > 0) cnt[d - 1]++;
        }
    }
    for (int i = 0; i < N - 1; i++) cout << cnt[i] / 2 << endl;
}