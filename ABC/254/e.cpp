#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

ll ans;
int k;
void BFS(const Graph &G, int s) {
    int N = G.size();
    vector<int> seen(N, -1);
    seen[s] = 0;
    queue<int> todo;
    todo.push(s);
    while (!todo.empty()) {
        int w = todo.front();
        todo.pop();
        ans += w + 1;
        if (seen[w] == k) continue;
        for (auto next_w: G[w]) {
            if (seen[next_w] != -1) continue;
            seen[next_w] = seen[w] + 1;
            todo.push(next_w);
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x; cin >> x >> k; x--;
        ans = 0;
        BFS(G, x);
        cout << ans << endl;
    }
}