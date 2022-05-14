#include <bits/stdc++.h>
using namespace std;
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
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    UnionFind uf(N);
    vector<int> ans;
    ans.push_back(0);
    set<int> used;
    int n = 0;
    for (int i = N - 1; i >= 1; i--) {
        n++;
        used.insert(i);

        int joint = 0;
        for (auto v: G[i]) {
            if (used.count(v) && uf.unite(i, v)) joint++;
        }
        n -= joint;
        ans.push_back(n);
    }
    reverse(ans.begin(), ans.end());
    for (int a: ans) cout << a << endl;
}