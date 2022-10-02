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
    rep(i, E) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    vector<bool> used(V, false);
    vector<ll> dist(V, INF);

    dist[r] = 0;

    rep(i, V) {
        int min_v = -1;
        ll min_dist = INF;

        rep(j, V) {
            if (!used[j] && min_dist > dist[j]) {
                min_dist = dist[j];
                min_v = j;
            }
        }

        if (min_v == -1) break;

        for (auto e: G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }

        used[min_v] = true;
    }

    rep(i, V) {
        if (dist[i] < INF) cout << dist[i] << endl;
        else cout << "INF" << endl;
    }
}
