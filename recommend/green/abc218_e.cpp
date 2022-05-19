#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<ll, pair<int, int>>;

struct Unionfind {
    vector<int> par, siz;
    
    Unionfind(int n): par(n, -1), siz(n, 1) {};

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

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        ll c; cin >> c;
        edges[i] = Edge(c, make_pair(a, b));
    }
    sort(edges.begin(), edges.end());

    Unionfind uf(N);
    vector<ll> cost;
    for (int i = 0; i < M; i++) {
        ll c = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (uf.issame(a, b)) {
            cost.push_back(c);
            continue;
        }
        uf.unite(a, b);
    }
    ll ans = 0;
    for (auto c: cost) if (c > 0) ans += c;
    cout << ans << endl;
}