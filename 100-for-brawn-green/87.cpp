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
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    vector<ll> ans(M);
    UnionFind uf(N);

    for (int i = M - 1; i >= 0; i--) {
        if (!(uf.issame(A[i], B[i]))) {
            ans[i] = 1LL * uf.size(A[i]) * uf.size(B[i]);
        }

        uf.unite(A[i], B[i]);
    }
    
    for (int i = 1; i < M; i++) ans[i] += ans[i - 1];
    rep(i, M) cout << ans[i] << endl;
}
