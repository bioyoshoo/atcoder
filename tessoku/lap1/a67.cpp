#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Edge = pair<int, pair<int, int>>;

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
    vector<Edge> edges(M);

    rep(i, M) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        edges[i] = Edge(c, make_pair(a, b));
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    rep(i, M) {
        int u, v; tie(u, v) = edges[i].second;
        int w = edges[i].first;

        if (uf.issame(u, v)) continue;

        uf.unite(u, v);
        ans += w;
    }

    cout << ans << endl;
}
