#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<bool> seen;

void DFS(const Graph &G, int v, int &ans) {
    seen[v] = true;
    ans++;
    if (ans >= 1e6) return;

    for (auto nv: G[v]) {
        if (seen[nv]) continue;
        DFS(G, nv, ans);
    }
    seen[v] = false;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);

    int ans = 0;
    DFS(G, 0, ans);

    cout << min(ans, (int)1e6) << endl;
}
