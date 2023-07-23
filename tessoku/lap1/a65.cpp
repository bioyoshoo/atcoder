#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> seen;
void DFS(const Graph &G, int v = 0, int p = -1) {
    int sum = 0;
    for (auto nv: G[v]) {
        if (nv == p) continue;
        DFS(G, nv, v);
        sum += seen[nv] + 1;
    }
    seen[v] = sum;
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int y = 1; y <= N - 1; y++) {
        int x; cin >> x; x--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    seen.resize(N);
    DFS(G);

    rep(x, N) cout << seen[x] << " ";
    cout << endl;
}
