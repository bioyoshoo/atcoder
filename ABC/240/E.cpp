#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v, vector<bool> &seen, vector<int> &leaf, int &id) {
    seen.at(v) = true;

    if (v != 0 && G.at(v).size() == 1) {
        id++;
        leaf.at(v) = id;
        return;
    }
    for (auto next_v: G.at(v)) {
        if (seen.at(next_v)) continue;
        dfs(G, next_v, seen, leaf, id);
    }
}

void dfs2(const Graph &G, int v, vector<bool> &seen, const vector<int> &leaf, vector<vector<int>> &LR) {
    seen.at(v) = true;

    if (leaf.at(v) != -1) {
        LR.at(v).at(0) = leaf.at(v);
        LR.at(v).at(1) = leaf.at(v);
        return;
    }
    else {
        for (auto next_v: G.at(v)) {
            if (seen.at(next_v)) continue;
            dfs2(G, next_v, seen, leaf, LR);
            LR.at(v).at(0) = min(LR.at(v).at(0), LR.at(next_v).at(0));
            LR.at(v).at(1) = max(LR.at(v).at(1), LR.at(next_v).at(1));
    }
    
    }
}
int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u - 1).push_back(v - 1);
        G.at(v - 1).push_back(u - 1);
    }

    vector<bool> seen(N, false);
    vector<int> leaf(N, -1);
    int id = 0;
    dfs(G, 0, seen, leaf, id);

    vector<vector<int>> LR(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        LR.at(i).at(0) = 1e6;
        LR.at(i).at(1) = -1e6;
    }
    
    seen.assign(N, false);
    dfs2(G, 0, seen, leaf, LR);

    for (int i = 0; i < N; i++) {
        cout << LR.at(i).at(0) << " " << LR.at(i).at(1) << endl;
    }   
}