#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;

ll dp[1100000][2];
void DFS(const Graph &G, int v, int p = -1) {
    dp[v][0] = 1; dp[v][1] = 1;
    for (auto next_v: G[v]) {
        if (next_v == p) continue;
        DFS(G, next_v, v);
        dp[v][0] *= dp[next_v][0] + dp[next_v][1] % mod;
        dp[v][0] %= mod;
        dp[v][1] *= dp[next_v][0] % mod;
        dp[v][1] %= mod;
    }
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    DFS(G, 0);
    cout << (dp[0][0] + dp[0][1]) % mod << endl;
}