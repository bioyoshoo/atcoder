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
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, N) {
        vector<int> ans = G[i];
        cout << ans.size() << " ";
        if (ans.size() == 0) {
            cout << endl;
            continue;
        }

        sort(ans.begin(), ans.end());
        for (auto a: ans) cout << a + 1 << " ";
        cout << endl;
    }
}
