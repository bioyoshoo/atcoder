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
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    UnionFind uf(N);

    rep(i, Q) {
        int q, u, v; cin >> q >> u >> v; u--; v--;
        if (q == 1) {
            uf.unite(u, v);
        }
        else if (q == 2) {
            if (uf.issame(u, v)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
