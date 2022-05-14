#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);
    Unionfind uf(N);
    for (int i = 0; i < M; i++) {
        ll a, b; cin >> a >> b; a--; b--;
        uf.unite(a, b);
    }
    map<int, ll> mp;
    for (int x = 0; x < N; x++) {
        mp[uf.root(x)] += B[x] - A[x];
    }
    bool ans = true;
    for (auto m: mp) {
        if (m.second != 0) {
            ans = false;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}