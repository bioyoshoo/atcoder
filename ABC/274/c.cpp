#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> depth;
void DFS(const Graph &G, int v = 0, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto next_v: G[v]) {
        if (next_v == p) continue;
        DFS(G, next_v, v, d + 1);
    }
}

int main() {
    int N; cin >> N;
    Graph G(2*N + 1);
    rep(i, N) {
        int a; cin >> a; a--;
        G[a].push_back(2 * i + 1);
        G[a].push_back(2 * (i + 1));
    }

    depth.resize(2*N + 1);
    DFS(G);

    for (auto ans: depth) cout << ans << endl;
}