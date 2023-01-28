#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;


int main() {
    int N, M; cin >> N >> M;
    int A = 0;
    rep(i, N) {
        int a; cin >> a;
        if (a == 1) A += (1 << i);
    }

    Graph G(1 << N);
    set<int> dp;
    dp.insert(A);

    rep(i, M) {
        int x, y, z; cin >> x >> y >> z; x--; y--; z--;
        int state = 0;
        rep(j, N) {
            if (j == x || j == y || j == z) state += (1 << j);
        }

        set<int> dp_new;
        for (auto s: dp) {
            // 反転しない
            dp_new.insert(s);
            // 反転する
            dp_new.insert(s ^ state);
            G[s].push_back(s ^ state);
        }
        dp = dp_new;
    }

    // BFS
    vector<int> dist(1 << N, -1);
    queue<int> que;

    dist[A] = 0;
    que.push(A);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv: G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << dist[(1 << N) - 1] << endl;
}
