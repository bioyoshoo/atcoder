#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int MAX = 1e9;
using Graph = map<int, vector<int>>;

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
    vector<pair<int, int>> P, Q;
    vector<int> A;
    bool is_zero = false;
    rep(i, N) {
        int a, b; cin >> a >> b; a--; b--;
        P.push_back({a, b});
        A.push_back(a), A.push_back(b);
        if (a == 0 || b == 0) is_zero = true; 
    }

    if (!is_zero) A.push_back(0);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    rep(i, N) {
        int a, b; tie(a, b) = P[i];
        int ans_a = lower_bound(A.begin(), A.end(), a) - A.begin();
        int ans_b = lower_bound(A.begin(), A.end(), b) - A.begin();
        Q.push_back({ans_a, ans_b});
    }

    int M = A.size();
    UnionFind uf(M);

    rep(i, N) {
        int a, b; tie(a, b) = Q[i];
        uf.unite(a, b);
    }

    int ans = -1;
    rep(x, M) {
        if (uf.root(x) == uf.root(0)) ans = max(ans, A[x]);
    }
    ans++;

    cout << ans << endl;
}
