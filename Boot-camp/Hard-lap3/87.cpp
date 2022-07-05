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
    int N, M, K; cin >> N >> M >> K;
    vector<int> friends(N);
    UnionFind uf(N);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        uf.unite(a, b);
        friends[a]++; friends[b]++;
    }
    
    vector<int> ans(N);
    rep(x, N) ans[x] = uf.size(x) - (friends[x] + 1);

    rep(i, K) {
        int c, d; cin >> c >> d; c--; d--;
        if (uf.issame(c, d)) {
            ans[c]--;
            ans[d]--;
        }
    }
    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}