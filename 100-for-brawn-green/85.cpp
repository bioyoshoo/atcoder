#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {};

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    int issame(int x, int y) {
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

    bool size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    rep(i, q) {
        int c, x, y; cin >> c >> x >> y;
        if (c == 0) uf.unite(x, y);
        else cout << uf.issame(x, y) << endl;
    }
}