#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> par;
void DFS(const Graph &G, int v, int p=-1) {
    par[v] = p;
    for (auto v2: G[v]) {
        if (v2 == p) continue;
        DFS(G, v2, v);
    }
}

int main() {
    int N, X, Y; cin >> N >> X >> Y;
    X--; Y--;

    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    par.assign(N, -1);
    DFS(G, X);

    vector<int> ans;
    int x = Y;
    while (x != -1) {
        ans.push_back(x);
        x = par[x];
    }
    reverse(ans.begin(), ans.end());

    for (auto a: ans) cout << a + 1 << " ";
    cout << endl;
}
