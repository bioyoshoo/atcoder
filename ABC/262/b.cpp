#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)


int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> T(N, vector<int>(N, 0));
    rep(i, M) {
        int u, v; cin >> u >> v; u--; v--;
        T[u][v] = 1;
        T[v][u] = 1;
    }

    int ans = 0;
    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            for (int c = b + 1; c < N; c++) {
                if (T[a][b] == 0) continue;
                if (T[b][c] == 0) continue;
                if (T[c][a] == 0) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
}