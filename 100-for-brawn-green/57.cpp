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
    int n, k; cin >> n >> k;
    Graph G(n);
    rep(i, k) {
        int x; cin >> x;

        if (x == 0) {
            int a, b; cin >> a >> b;
            a--; b--;

            vector<bool> used(n, false);
            vector<ll> dist(n, INF);
            dist[a] = 0;

            rep(j, n) {
                int min_v = -1;
                ll min_dist = INF;
                rep(v, n) {
                    if (!used[v] && min_dist > dist[v]) {
                        min_v = v;
                        min_dist = dist[v];
                    }
                }

                if (min_v == -1) break;

                for (auto e: G[min_v]) {
                    chmin(dist[e.to], dist[min_v] + e.w);
                }
                used[min_v] = true;
            }

            if (dist[b] == INF) cout << -1 << endl;
            else cout << dist[b] << endl;
        }
        else {
            int c, d;
            ll e;
            cin >> c >> d >> e;
            c--; d--;
            G[c].push_back({d, e});
            G[d].push_back({c, e});
        }
    }
}