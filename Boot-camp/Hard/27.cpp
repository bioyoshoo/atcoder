#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void DFS(const Graph &G, int v, int p, vector<int64_t> &res) {
    if (p != -1) res.at(v) += res.at(p);

    for (auto next_v: G.at(v)) {
        if (next_v == p) continue;
        DFS(G, next_v, v, res);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<int64_t> ans(N, 0);
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        ans.at(p) += x;
    }

    DFS(G, 0, -1, ans);

    for (int i = 0; i < N; i++) cout << ans.at(i) << " ";
    cout << endl;
}