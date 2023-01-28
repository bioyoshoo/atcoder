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
    int N; cin >> N;
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    vector<tuple<ll, ll, ll>> C(N);
    int start = -1, goal = -1;
    rep(i, N) {
        ll x, y, r; cin >> x >> y >> r;
        C[i] = {x, y, r};
        
        ll ds = (sx - x)*(sx - x) + (sy - y)*(sy - y);
        if (r*r == ds) start = i;
        
        ll dt = (tx - x)*(tx - x) + (ty - y)*(ty - y);
        if (r*r == dt) goal = i;
    }

    UnionFind uf(N);
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            ll xi, yi, ri;
            tie(xi, yi, ri) = C[i];
            ll xj, yj, rj;
            tie(xj, yj, rj) = C[j];

            ll d = (xi - xj)*(xi - xj) + (yi - yj)*(yi - yj);

            bool flag = false;
            // ok outer
            if (d <= (ri + rj)*(ri + rj) && (ri - rj)*(ri - rj) <= d) flag = true;

            if (flag) uf.unite(i, j);
        }
    }
    if (uf.root(start) == uf.root(goal)) cout << "Yes" << endl;
    else cout << "No" << endl;
}