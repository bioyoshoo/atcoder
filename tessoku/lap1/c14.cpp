#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int N, M;
struct Edge {
    int to, w;
};
using Graph = vector<Edge>;
Graph G[100010];

int dist[100010];
bool seen[100010];

void DFS(int u) {
    seen[u] = true;

    for (auto e: G[u]) {
        if (seen[e.to]) continue;
        if (dist[u] == dist[e.to] + e.w) {
            DFS(e.to);
        }
    }
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        G[a].push_back(Edge{b, c});
        G[b].push_back(Edge{a, c});
    }

    // dist: 最短距離, dp: 経路の数
    rep(i, N) dist[i] = INF;
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        int u, d; tie(d, u) = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto e: G[u]) {
            if (chmin(dist[e.to], dist[u] + e.w)) {
                pq.push({dist[e.to], e.to});
            }
        }
    }

    rep(i, N) seen[i] = false;
    DFS(N - 1);

    int ans = 0;
    rep(i, N) if (seen[i]) ans++;

    cout << ans << endl;
}
