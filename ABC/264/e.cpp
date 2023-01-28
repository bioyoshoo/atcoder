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
    int N, M, E; cin >> N >> M >> E;
    vector<int> U(E), V(E);
    set<int> broken;
    rep(i, E) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
    }
    int Q; cin >> Q;
    vector<int> X(Q);
    rep(i, Q) {
        cin >> X[i];
        X[i]--;
        broken.insert(X[i]);
    }

    UnionFind uf(N + M);
    set<int> ok;
    int ans = 0;
    // 最初から最後までついている
    rep(i, E) {
        if (broken.count(i)) continue;
        // 都市同士
        if (V[i] < N) uf.unite(U[i], V[i]);
        // 都市-発電所
        if (U[i] < N && V[i] >= N) {
            uf.unite(U[i], V[i]);
            ok.insert(U[i]);
        }
        // 発電所同士は何もしない
    }

    vector<int> ans;
    int sum = 0;
    for (int i = Q - 1; i >= 0; i--) {
        int u = U[X[i]], v = V[X[i]];
        // 都市同士
        if (v < N) {
            if (ok.count(u) && ok.count(v)) continue;
            if (!ok.count(u) && ok.count(v))
            uf.unite(u, v);
        // 都市-発電所
        if (u < N && v >= N) {

            uf.unite(u, v);
            ok.insert(u);
        }
        // 発電所同士は何もしない
    }
}