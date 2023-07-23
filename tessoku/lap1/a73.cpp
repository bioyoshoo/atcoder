#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

struct Edge {
    int to, cap, tree;
};

class Dijkstra {
public:
    int siz = 0;
    vector<Edge> G[10000];

    void init(int N) {
        siz = N;
        rep(i, siz) G[i].clear();
    }

    void add_edge(int a, int b, int c, int d) {
        G[a].push_back(Edge{ b, c, d });
        G[b].push_back(Edge{ a, c, d });
    }

    pair<int, int> solve(int s, int t) {
        vector<int> dist(siz, INF), tree(siz);
        vector<int> used(siz, false);

        dist[s] = 0; tree[0] = 0;

        rep(i, siz) {
            int min_dist = INF, min_v = -1;

            rep(v, siz) {
                if (!used[v] && dist[v] < min_dist) {
                    min_dist = dist[v];
                    min_v = v;
                }
            }

            if (min_v == -1) break;

            for (auto e: G[min_v]) {
                if (dist[e.to] > dist[min_v] + e.cap) {
                    dist[e.to] = dist[min_v] + e.cap;
                    tree[e.to] = tree[min_v] + e.tree;
                }
                if ((dist[e.to] == dist[min_v] + e.cap) && (tree[e.to] < tree[min_v] + e.tree)) {
                    tree[e.to] = tree[min_v] + e.tree;
                }
            }

            used[min_v] = true;
        }

        return make_pair(dist[t], tree[t]);
    }
};

int main() {
    int N, M; cin >> N >> M;
    Dijkstra Z; Z.init(N);
    rep(i, M) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
        Z.add_edge(a, b, c, d);
    }

    int d, t;
    tie(d, t) = Z.solve(0, N - 1);
    cout << d << " " << t << endl;
}   
