#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> ans;
vector<bool> seen;
void DFS(const Graph &G, int v=0) {
    ans.push_back(v);
    seen[v] = true;
    for (auto v2: G[v]) {
        if (seen[v2]) continue;
        DFS(G, v2);
    }
    ans.push_back(v);
}

int main() {
    int n; cin >> n;
    Graph G(n);
    rep(i, n) {
        int u, k; cin >> u >> k; u--;
        rep(j, k) {
            int v; cin >> v; v--;
            G[u].push_back(v);
        }
    }

    seen.assign(n, false);
    rep(x, n) {
        if (seen[x]) continue;
        DFS(G, x);
    }
    
    vector<vector<int>> res(n);
    int m = ans.size();
    rep(i, m) res[ans[i]].push_back(i + 1);

    rep(i, n) {
        cout << i + 1 << " " << res[i][0] << " " << res[i][1] << endl;
    }
}