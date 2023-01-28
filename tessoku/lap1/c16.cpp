#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to, leave_time, arrive_time;
};
using Graph = vector<vector<Edge>>;

int N, M, K;

int DFS(const Graph &G, int v, int cur_time) {
    int res = 0;
    for (auto e: G[v]) {
        if (cur_time > e.leave_time) continue;
        int cand = DFS(G, e.to, e.arrive_time + K);
        res = max(res, cand + 1);
    }
    return res;
}

int main() {
    cin >> N >> M >> K;
    Graph G(N);
    rep(i, M) {
        int a, s, b, t; cin >> a >> s >> b >> t; a--; b--;
        G[a].push_back(Edge{b, s, t});
    }

    int ans = 0;
    rep(x, N) {
        ans = max(ans, DFS(G, x, 0));
    }
    
    cout << ans << endl;
}
