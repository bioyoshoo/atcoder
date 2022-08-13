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
    for (auto v2: G[v]) {
        if (seen[v2]) continue;
        DFS(G, v2);
    }
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    int ans = 0;
    rep(i, M) {
        Graph G(N);
        int s = -1;
        rep(j, M) {
            if (i == j) continue;
            G[A[j]].push_back(B[j]);
            G[B[j]].push_back(A[j]);
            s = A[j];
        }

        seen.assign(N, false);
        DFS(G, s);

        bool flag = false;
        rep(k, N) if (!seen[k]) flag = true;

        if (flag) ans++;
    }
    cout << ans << endl;
}