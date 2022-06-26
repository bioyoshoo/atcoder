#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

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
    vector<int> A(M), B(M);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        A[i] = a; B[i] = b;
    }
    int ans = 0;
    rep(m, M) {
        UnionFind uf(N);
        for (int i = 0; i < M; i++) {
            if (i == m) continue;
            uf.unite(A[i], B[i]);
        }
        int j = 0;
        rep(i, N) if (uf.root(i) == i) j++;
        if (j > 1) ans++;
    }
    cout << ans << endl;
}