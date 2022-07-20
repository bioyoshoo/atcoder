#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to;
    ll w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;

vector<int> ans;
void DFS(const Graph &G, int v=0, int p=-1, int c=0) {
    ans[v] = c;
    for (auto e: G[v]) {
        if (e.to == p) continue;

        if (e.w % 2 == 0) DFS(G, e.to, v, c);
        else DFS(G, e.to, v, 1 - c);
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

    ans.resize(N);
    DFS(G);

    rep(i, N) cout << ans[i] << endl;
}