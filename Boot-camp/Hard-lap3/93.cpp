#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;

vector<ll> dp;
void DFS(const Graph &G, int v, int p=-1, ll d=0) {
    dp[v] = d;
    for (auto e: G[v]) {
        if (e.to == p) continue;
        DFS(G, e.to, v, d + e.w);
    }
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(Edge(b, w));
        G[b].push_back(Edge(a, w));
    }
    int Q, K; cin >> Q >> K; K--;

    dp.resize(N);
    DFS(G, K);

    rep(i, Q) {
        int x, y; cin >> x >> y; x--; y--;
        cout << dp[x] + dp[y] << endl;
    }
}