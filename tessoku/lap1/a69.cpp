#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct Edge {
    int to, cap, rev;
};

class MaximumFlow {
public:
    int siz = 0;
    bool used[400];
    vector<Edge> G[400];

    void init(int N) {
        siz = N;
        rep(i, siz) G[i].clear();
    }

    void add_edge(int a, int b, int c) {
        int a_rev = G[b].size();
        int b_rev = G[a].size();
        G[a].push_back(Edge{b, c, a_rev});
        G[b].push_back(Edge{a, 0, b_rev});
    }

    int dfs(int pos, int goal, int f) {
        if (pos == goal) return f;
        used[pos] = true;
        for (auto &e: G[pos]) {
            if (e.cap == 0) continue;
            if (used[e.to]) continue;

            int flow = dfs(e.to, goal, min(f, e.cap));

            if (flow > 0) {
                e.cap -= flow;
                G[e.to][e.rev].cap += flow;
                return flow;
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int total = 0;
        while (true) {
            rep(i, siz) used[i] = false;
            int F = dfs(s, t, 1e9);
            if (F == 0) break;
            total += F;
        }
        return total;
    }
};

int main() {
    int N; cin >> N;
    MaximumFlow Z; Z.init(2*N + 2);

    rep(i, N) rep(j, N) {
        char c; cin >> c;
        if (c == '#') Z.add_edge(i, N + j, 1);
    }
    rep(i, N) {
        Z.add_edge(2*N, i, 1);
        Z.add_edge(N + i, 2*N + 1, 1);
    }

    cout << Z.max_flow(2*N, 2*N + 1) << endl;
}
