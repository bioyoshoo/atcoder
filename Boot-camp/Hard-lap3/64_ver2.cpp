#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

vector<bool> seen;
void DFS(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v: G[v]) {
        if (seen[next_v] != false) continue;
        DFS(G, next_v);
    }
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        A[i] = a; B[i] = b;
    }
    int ans = 0;
    rep(m, M) {
        Graph G(N);
        rep(i, M) {
            if (i == m) continue;
            G[A[i]].push_back(B[i]);
            G[B[i]].push_back(A[i]);
        }
        seen.assign(N, false);
        DFS(G, 0);
        rep(x, N) {
            if (seen[x] == false) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}