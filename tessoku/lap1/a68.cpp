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
    bool used[410];
    vector<Edge> G[410];

    void init(int N) {
        siz = N;
        rep(i, N) G[i].clear();
    }

    void add_edges(int a, int b, int c) {
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
        int total_flow = 0;
        while (true) {
            rep(i, siz) used[i] = false;
            int F = dfs(s, t, 1e9);
            if (F == 0) break;
            total_flow += F;
        }
        
        return total_flow;
    }
};

int main() {
    int N, M; cin >> N >> M;
    MaximumFlow Z; Z.init(N);

    rep(i, M) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        Z.add_edges(a, b, c);
    }
    
    cout << Z.max_flow(0, N - 1) << endl;
}
