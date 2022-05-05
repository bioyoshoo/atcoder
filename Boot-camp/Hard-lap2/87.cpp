#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

struct Unionfind {
    vector<int> par, siz;
    Unionfind(int n) : par(n, -1), siz(n, 1) {};

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
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
    int N, M, K;
    cin >> N >> M >> K;
    Unionfind uf(N);
    Graph F(N), B(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        uf.unite(a, b);
        F[a].push_back(b);
        F[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int c, d; cin >> c >> d; c--; d--;
        B[c].push_back(d);
        B[d].push_back(c);
    }

    for (int x = 0; x < N; x++) {
        int ans = uf.size(x);
        // myself
        ans -= 1;
        // direct freinds
        ans -= F[x].size();
        // block people in the team
        int sub = 0;
        for (int b: B[x]) {
            if (uf.root(x) == uf.root(b)) sub++;
        }
        ans -= sub;
        cout << ans << " ";
    }
    cout << endl;
}