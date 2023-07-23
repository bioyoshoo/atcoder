#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, N) {
        cout << i + 1 << ": {";
        for (int j = 0; j < (int)G[i].size(); j++) {
            if (j > 0) cout  << ", ";
            cout << G[i][j] + 1;
        }
        cout << "}" << endl;
    }
}
