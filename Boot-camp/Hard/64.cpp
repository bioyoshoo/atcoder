#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

struct UnionFind {
    vector<int> par, siz;
    
    UnionFind(int n) : par(n, -1), siz(n, 1) {};

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
    vector<pair<int, int>> V(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V.at(i) = {a, b};
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        UnionFind uf(N);
        for (int j = 0; j < M; j++) {  
            if (i == j) continue;
            uf.unite(V.at(j).first, V.at(j).second);
        }

        int parents = 0;
        for (int x = 0; x < N; x++) {
            if (uf.root(x) == x) parents++;
        }

        if (parents > 1) ans++;
    }

    cout << ans << endl;
}