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
    int size_ = 0;
    bool used[200];
    vector<Edge> G[200];

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
    vector<int> P(N), A(M), B(M);
    rep(i, N) cin >> P[i];
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    FordFulkerson Z; Z.init(N + 2);
    int offset = 0;
    
    // グラフの作成
    rep(i, N) {
        if (P[i] >= 0) {
            Z.add_edge(N, i, P[i]);
            offset += P[i];
        }
        else Z.add_edge(i, N + 1, -P[i]);
    }
    // 条件
    rep(i, M) {
        Z.add_edge(A[i], B[i], INF);
    }

    int ans = offset - Z.max_flow(N, N + 1);

    cout << ans << endl;
}
