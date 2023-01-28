#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> dp;
void DFS(const Graph &G, int v=0, int p=-1, int sum=0) {
    dp[v] += sum;
    for (auto v2: G[v]) {
        if (v2 == p) continue;
        DFS(G, v2, v, dp[v]);
    }
}

int main() {
    int N, Q; cin >> N >> Q;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dp.resize(N);
    rep(i, Q) {
        int p, x; cin >> p >> x; p--;
        dp[p] += x;
    }

    DFS(G);

    rep(i, N) cout << dp[i] << " ";
    cout << endl;
}