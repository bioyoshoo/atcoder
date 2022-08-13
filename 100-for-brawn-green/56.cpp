#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {};
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
        ll w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    vector<ll> dist(V, INF);
    dist[r] = 0;

    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> todo;
    todo.push({0, r});

    while (!todo.empty()) {
        int v = todo.top().second;
        ll d = todo.top().first;
        todo.pop();

        if (d > dist[v]) continue;

        for (auto e: G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                todo.push({dist[e.to], e.to});
            }
        }
    }

    rep(x, V) {
        if (dist[x] == INF) cout << "INF" << endl;
        else cout << dist[x] << endl;
    }
}