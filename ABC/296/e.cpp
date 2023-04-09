#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<bool> seen, cycle;
int DFS(const Graph &G, int v) {
    if (seen[v] && !cycle[v]) {
        cycle[v] = true;
        return 0;
    }
    else seen[v] = true;

    // 行きがけ
    for (auto nv: G[v]) {
        if (cycle[nv]) continue;
        DFS(G, nv);
    }

    // 帰りがけ
    for (auto nv: G[v]) {
        if (cycle[nv]) cycle[v] = true;
    }

    return 0;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i]; A[i]--;
    }

    Graph G(N);
    rep(i, N) {
        G[i].push_back(A[i]);
    }

    seen.assign(N, false);
    cycle.assign(N, false);
    
    rep(x, N) {
        if (seen[x]) continue;
        DFS(G, x);
    }

    int ans = 0;
    rep(x, N) if (cycle[x]) ans++;
    cout << ans << endl;
}
