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
    int N, M, K; cin >> N >> M >> K;
    vector<Edge> edges(M);
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        edges[i] = Edge(c, make_pair(a, b));
    }

    if (N <= K) cout << 0 << endl;
    else {
        sort(edges.begin(), edges.end());

        UnionFind uf(N);
        int ans = 0;
        int cnt = 0;
        rep(i, M) {
            int w = edges[i].first;
            int u = edges[i].second.first, v = edges[i].second.second;

            if (uf.issame(u, v)) continue;
            uf.unite(u, v);
            ans += w;
            cnt++;

            if (cnt == N - K) break;
        }

        cout << ans << endl;
    }
}
