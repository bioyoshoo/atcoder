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

    vector<pair<int, int>> V(M);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        V[i] = make_pair(a, b);
    }

    int Q; cin >> Q;
    vector<vector<int>> query(Q);
    set<int> stop;
    rep(i, Q) {
        int q; cin >> q;
        query[i].push_back(q);

        if (q == 1) {
            int x; cin >> x; x--;
            query[i].push_back(x);
            stop.insert(x);
        }
        else if (q == 2) {
            int x, y; cin >> x >> y; x--; y--;
            query[i].push_back(x); query[i].push_back(y);
        }
    }
    
    UnionFind uf(N);

    // 最後まで運休しないものを先につないでおく
    rep(x, M) {
        if (!stop.count(x)) {
            int a, b; tie(a, b) = V[x];
            uf.unite(a, b);
        }
    }

    // query を逆からよむ
    reverse(query.begin(), query.end());

    vector<string> ans;
    rep(i, Q) {
        int q = query[i][0];
        if (q == 1) {
            int x = query[i][1];
            int a, b; tie(a, b) = V[x];
            uf.unite(a, b);
        }
        else if (q == 2) {
            int u = query[i][1], v = query[i][2];
            if (uf.issame(u, v)) ans.push_back("Yes");
            else ans.push_back("No");
        }
    }
    reverse(ans.begin(), ans.end());

    for (auto a: ans) cout << a << endl;
}
