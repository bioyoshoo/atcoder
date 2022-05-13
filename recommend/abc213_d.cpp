#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<int> ans;
void DFS(const Graph &G, int v = 0, int p = -1) {
    ans.push_back(v);
    for (auto next_v: G[v]) {
        if (next_v == p) continue;
        DFS(G, next_v, v);
        ans.push_back(v);
    }
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; i++) sort(G[i].begin(), G[i].end());

    DFS(G);
    for (auto a: ans) cout << a + 1 << " ";
    cout << endl;
}