#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Unionfind {
    vector<int> par, siz;
    
    Unionfind(int n): par(n, -1), siz(n, 1) {};

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
        if (siz[y] > siz[x]) swap(x, y);
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
    vector<int> deg(N);
    Unionfind uf(N);
    bool ans = true;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
<<<<<<< HEAD
        table[a].push_back(b);
        table[b].push_back(a);
    }
    bool ans = true;
    
    for (int i = 0; i < N; i++) 
        if (size > 2) ans = false;
    }
    
    seen.assign(N, false);
    for (int v = 0; v < N; v++) {
        if (seen[v]) continue;
        if (DFS(table, v)) ans = false;
=======
        if (uf.issame(a, b)) {
            ans = false;
            break;
        }
        else uf.unite(a, b);
        deg[a]++;
        deg[b]++;
>>>>>>> 88d8cd0868086c6c36f451984093b5d403be6c53
    }
    for (int i = 0; i < N; i++) if (deg[i] >= 3) ans = false;

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}