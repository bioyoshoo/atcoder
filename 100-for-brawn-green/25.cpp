#include <bits/stdc++.h>
using namespace std;
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

    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    while (true) {
        int w, h; cin >> w >> h;
        if (w == 0 && h == 0) break;

        vector<vector<int>> T(h, vector<int>(w));
        rep(i, h) rep(j, w) cin >> T[i][j];

        int n = h * w;
        Graph G(n);
        rep(x, h) rep(y, w) {
            if (T[x][y] == 0) continue;
            int u = w * x + y;
            rep(r, 8) {
                int x2 = x + dx[r], y2 = y + dy[r];
                if (x2 < 0 || x2 >= h) continue;
                if (y2 < 0 || y2 >= w) continue;
                if (T[x2][y2] == 0) continue;
                int v = w * x2 + y2;
                G[u].push_back(v);
            }
        }

        seen.assign(n, false);
        int ans = 0;
        rep(i, h) rep(j, w) {
            if (T[i][j] == 0) continue;
            int x = w * i + j;
            if (seen[x]) continue;
            ans++;
            DFS(G, x);
        }
        cout << ans << endl;
    }
}