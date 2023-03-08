#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) { };

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int N, M; cin >> N >> M;
    UnionFind uf(N);
    vector<pair<int, int>> edges(M);

    rep(i, M) {
        int u, v; cin >> u >> v; u--; v--;
        edges[i] = make_pair(u, v);

        if (!uf.issame(u, v)) uf.unite(u, v);
    }

    // 頂点がどのグループに属すか
    vector<int> groups(N);
    // groupごとに頂点の数を記録
    map<int, int> V;
    rep(x, N) {
        int root = uf.root(x);
        groups[x] = root;
        V[root] += 1;
    }

    map<int, int> E;
    rep(i, M) {
        // 辺の属するグループ
        int g = groups[edges[i].first];
        E[g] += 1;
    }

    bool ans = true;
    for (auto [g, v]: V) {
        int e = E[g];
        if (e != v) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
