#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<int> seen;
void DFS(const Graph &G, int x, int p, int goal) {
    seen[x] = p;
    if (x == goal) return;

    for (auto nx: G[x]) {
        if (seen[nx] != -1) continue;
        DFS(G, nx, x, goal);
    }
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, -1);
    DFS(G, 0, 0, N - 1);

    vector<int> ans;
    int x = N - 1;
    while (x != seen[x]) {
        ans.push_back(x);
        x = seen[x];
    }
    ans.push_back(x);
    reverse(ans.begin(), ans.end());

    for (auto a: ans) cout << a + 1 << " ";
    cout << endl;
}
