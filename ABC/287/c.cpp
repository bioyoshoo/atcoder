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
    bool ans = true;
    rep(i, M) {
        int u, v; cin >> u >> v; u--; v--;
        
        if (uf.issame(u, v)) ans = false;
        else uf.unite(u, v);
    }

    if (ans) {
        int par = 0;
        rep(x, N) {
            if (uf.root(x) == x) par++;
        }
        if (par == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}