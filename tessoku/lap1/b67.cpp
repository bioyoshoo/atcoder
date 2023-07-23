#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using edge = pair<ll, pair<int, int>>;

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
    vector<edge> Edges(M);
    rep(i, M) {
        int a, b; ll c; cin >> a >> b >> c; a--; b--;
        Edges[i] = edge(-c, make_pair(a, b));
    }

    sort(Edges.begin(), Edges.end());

    ll ans = 0;
    UnionFind uf(N);
    rep(i, M) {
        int u = Edges[i].second.first, v = Edges[i].second.second;
        ll w = Edges[i].first;

        if (uf.issame(u, v)) continue;

        uf.unite(u, v);
        ans += -w;
    }

    cout << ans << endl;
}
