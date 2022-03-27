#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
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
    
    UnionFind uf(N);
    vector<pair<int, int>> friends(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
        friends[i] = make_pair(a, b);
    }
    
    vector<pair<int, int>> block(K);
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        block[i] = make_pair(c, d);
    }

    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i] = uf.size(i) - 1;
    }

    // 直接の友達をのぞく
    for (int i = 0; i < M; i++) {
        int x = friends[i].first, y = friends[i].second;
        ans[x]--;
        ans[y]--;
    }

    // blockの人を除く
    for (int i = 0; i < K; i++) {
        int x = block[i].first, y = block[i].second;
        if (uf.issame(x, y)) {
            ans[x]--;
            ans[y]--;
        }
    }

    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}