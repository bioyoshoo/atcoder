#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<bool> seen;
void DFS(const Graph &G, int v, vector<int> &log) {
    seen.at(v) = true;
    log.push_back(v);
    for (auto v2: G.at(v)) {
        if (seen.at(v2) != false) continue;
        DFS(G, v2, log);
    }
    log.push_back(v);
}

int main() {
    int n; cin >> n;
    Graph G(n);
    rep(i, n) {
        int u; cin >> u; u--;
        int k; cin >> k;
        rep(j, k) {
            int v; cin >> v; v--;
            G.at(u).push_back(v);
        }
    }
    
    seen.assign(n, false);
    vector<int> log;

    DFS(G, 0, log);
    vector<vector<int>> ans(n);
    int m = log.size();
    rep(i, m) {
        ans.at(log.at(i)).push_back(i + 1);
    }

    rep(i, n) {
        cout << i + 1 << " " << ans.at(i).at(0) << " " << ans.at(i).at(1) << endl;
    }
}