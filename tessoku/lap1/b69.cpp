#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

struct Edge {
    int to, cap, rev;
};

class FordFulkerson {
    public:
    int size_ = 1;
    bool used[100];
    vector<Edge> G[100];

    void init(int N) {
        size_ = N;
        rep(i, size_) G[i].clear();
    }

    void add_edge(int a, int b, int c) {
        int cur_a = G[a].size();
        int cur_b = G[b].size();
        G[a].push_back(Edge{b, c, cur_b});
        G[b].push_back(Edge{a, 0, cur_a});
    }

    int dfs(int pos, int goal, int F) {
        if (pos == goal) return F;
        used[pos] = true;
        for (auto &e: G[pos]) {
            if (e.cap == 0) continue;
            if (used[e.to]) continue;

            int flow = dfs(e.to, goal, min(e.cap, F));

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
            rep(i, size_) used[i] = false;
            int f = dfs(s, t, INF);

            if (f > 0) total += f;
            else break;
        }
        return total;
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<vector<char>> C(N, vector<char>(24));
    rep(i, N) rep(j, 24) cin >> C[i][j];

    FordFulkerson Z; Z.init(N + 26);
    rep(i, N) rep(j, 24) {
        if (C[i][j] == '1') Z.add_edge(i, N + j, 1);
    }
    rep(i, N) Z.add_edge(N + 24, i, 10);
    rep(j, 24) Z.add_edge(N + j, N + 25, M);

    int ans = Z.max_flow(N + 24, N + 25);
    if (ans == 24 * M) cout << "Yes" << endl;
    else cout << "No" << endl;
}
