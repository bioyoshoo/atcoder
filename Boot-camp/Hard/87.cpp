#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void DFS(const Graph &G, int v, set<int> &seen) {
    seen.insert(v);

    for (int next_v: G[v]) {
        if (seen.count(next_v)) continue;
        DFS(G, next_v, seen);
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<pair<int, int>> B(K);
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        B[i] = make_pair(c, d);
    }

    vector<int> groups(N, -1), group_id(N, -1);
    int id = 0;
    for (int i = 0; i < N; i++) {
        if (groups[i] != -1) continue;
        set<int> seen;
        DFS(G, i, seen);

        for (auto s: seen) {
            groups[s] = seen.size() - 1;
            group_id[s] = id;
        }
        id++;
    }

    // 直接の友人は除く
    for (int i = 0; i < N; i++) groups[i] -= G[i].size();

    // ブロック関係は除く
    for (int i = 0; i < K; i++) {
        int x = B[i].first, y = B[i].second;
        if (group_id[x] == group_id[y]) {
            groups[x] -= 1;
            groups[y] -= 1;
        }
    }

    for (int i = 0; i < N; i++) cout << groups[i] << " ";
    cout << endl;
}