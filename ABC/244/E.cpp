#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 998244353;
using Graph = vector<vector<int>>;

int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;

    Graph G(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    
}