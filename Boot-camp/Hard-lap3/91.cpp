#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;
struct Edge {
    int to;
    int id;
    Edge(int to, int id) : to(to), id(id) {};
};
using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

vector<int> ans;
void DFS(const Graph &G, int v, int p=-1, int c=-1) {
    int next_c = 0;
    for (auto e: G[v]) {
        if (e.to == p) continue;
        if (next_c == c) next_c++;
        ans[e.id] = next_c;
        DFS(G, e.to, v, next_c);
        next_c++;
    }
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(Edge(b, i));
        G[b].push_back(Edge(a, i));
    }
    int s = -1, deg = INF;
    rep(i, N) {
        if (chmin(deg, (int)G[i].size())) s = i;
    }

    ans.resize(N - 1);
    DFS(G, s);
    int max_deg = -1;
    rep(i, N - 1) max_deg = max(max_deg, (int)G[i].size());
    cout << max_deg << endl;
    rep(i, N - 1) cout << ans[i] + 1 << endl;
}