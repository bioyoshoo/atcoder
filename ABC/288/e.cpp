#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int N, M;
int C[5000];
int dp1[5000], dp2[5000];

bool DFS(const Graph &G, int t, int a, int cnt) {
    dp1[t] = cnt; dp2[a] = cnt;
    if (t == N - 1 && a == 0) return true;
    
    for (auto t_next: G[t]) {
        for (auto a_next: G[a]) {
            if (dp1[t_next] != -1) continue;
            if (dp2[a_next] != -1) continue;

            if (C[t_next] == C[a_next]) continue;

            if (DFS(G, t_next, a_next, cnt + 1)) return true;
        }
    }

    dp1[t] = -1; dp2[a] = -1;
    return false;
}

int main() {
    int T; cin >> T;
    rep(t, T) {
        cin >> N >> M;
        rep(i, 5000) {
            C[i] = 0; dp1[i] = -1; dp2[i] = -1;
        }
        rep(i, N) cin >> C[i];
        Graph G(N);
        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b; a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        if (DFS(G, 0, N - 1, 0)) cout << dp1[N - 1]  << endl;
        else cout << -1 << endl;
    }
}
