#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

vector<bool> seen;
vector<int> order;
void DFS(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v: G[v]) {
        if (seen[next_v]) continue;
        DFS(G, next_v);
    }
    order.push_back(v);
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y);
    }

    seen.assign(N, false);
    for (int v = 0; v < N; v++) {
        if (seen[v]) continue;
        DFS(G, v);
    }
    reverse(order.begin(), order.end());

    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++) {
        int v = order[i];
        for (auto next_v: G[v]) chmax(dp[next_v], dp[v] + 1);
    }

    int ans = -1;
    for (int i = 0; i < N; i++) chmax(ans, dp[i]);
    cout << ans << endl;
}