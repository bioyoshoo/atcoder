#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> ans;
vector<int> X;
void DFS(const Graph &G, int v, int p = -1) {
    if (p == -1) ans[v] = X[v];
    else ans[v] = ans[p] + X[v];

    for (auto next_v: G[v]) {
        if (next_v == p) continue;
        DFS(G, next_v, v);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    X.assign(N, 0);
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        X.at(p) += x;
    }

    ans.assign(N, 0);
    DFS(G, 0);

    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}