#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Edge = pair<ll, pair<int, int>>;

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
    int V, E; cin >> V >> E;
    UnionFind uf(V);
    vector<Edge> edges(E);
    rep(i, E) {
        int s, t, w; cin >> s >> t >> w;
        edges[i] = {w, {s, t}};
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    rep(i, E) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if (uf.issame(u, v)) continue;

        uf.unite(u, v);
        ans += w;
    }

    cout << ans << endl;
}