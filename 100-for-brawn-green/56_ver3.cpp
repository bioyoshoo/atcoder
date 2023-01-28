#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;
const ll INF = 1e18;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int V, E, r; cin >> V >> E >> r;
    Graph G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    vector<ll> dist(V, INF);
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> que;
    
    dist[r] = 0;
    que.push({dist[r], r});

    while (!que.empty()) {
        ll d = que.top().first;
        int v = que.top().second;
        que.pop();

        if (dist[v] < d) continue;

        for (auto e: G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push({dist[e.to], e.to});
            }
        }
    }

    rep(x, V) {
        if (dist[x] < INF) cout << dist[x] << endl;
        else cout << "INF" << endl;
    }
}
