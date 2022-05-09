#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
bool DFS(const Graph &G, int v) {
    if (seen[v]) return true;
    else seen[v] = true;

    for (auto next_v: G[v]) {
        if (DFS(G, next_v)) return true;
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> table(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        table[a].push_back(b);
        table[b].push_back(a);
    }
    bool ans = true;
    
    for (int i = 0; i < N; i++) {
        int size = table[i].size();
        if (size > 2) ans = false;
    }
    
    seen.assign(N, false);
    for (int v = 0; v < N; v++) {
        if (seen[v]) continue;
        if (DFS(table, v)) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}