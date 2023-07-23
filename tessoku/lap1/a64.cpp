#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; ll w; 
        cin >> a >> b >> w; a--; b--;
        G[a].push_back(Edge(b, w));
        G[b].push_back(Edge(a, w));
    }

    vector<ll> dist(N, INF);
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> que;

    dist[0] = 0;
    que.push({0, 0});

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (dist[v] < d) continue;

        for (auto nv: G[v]) {
            if (chmin(dist[nv.to], dist[v] + nv.w)) {
                que.push({dist[nv.to], nv.to});
            }
        }
    }

    rep(x, N) {
        if (dist[x] != INF) cout << dist[x] << endl; 
        else cout << -1 << endl;
    }
}
