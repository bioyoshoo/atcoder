#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int N, M;
Graph G;
vector<set<int>> edges;
ll ans = 0;

void check(int v, int p=-1, int d = 0) {
    if (d == 0) {
        for (auto nv: G[v]) {
            check(nv, v, d + 1);
        }
    }
    else if (d == 1) {
        for (auto nv: G[v]) {
            check(nv, p, d + 1);
        }
    }
    else if (d == 2) {
        if (edges[p].count(v)) return;
        else {
            edges[p].insert(v);
            G[p].push_back(v);
            ans++;
            
            for (auto nv: G[v]) {
                check(nv, p, 1);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);
    edges.resize(N);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        edges[a].insert(b);
    }

    rep(x, N) {
        check(x);
    }

    cout << ans << endl;
}
