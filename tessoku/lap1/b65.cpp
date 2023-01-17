#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> ranks;
void DFS(const Graph &G, int v, int p) {
    int r = -1;
    for (auto nv: G[v]) {
        if (nv == p) continue;
        DFS(G, nv, v);
        r = max(r, ranks[nv]);
    }
    ranks[v] = r + 1;
}

int main() {
    int N, T; cin >> N >> T; T--;
    Graph G(N);
    rep(i, N - 1) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ranks.assign(N, -1);
    DFS(G, T, -1);

    for (auto r: ranks) cout << r << " ";
    cout << endl;
}
