#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v, vector<int> &depth) {
    depth.at(v) = 0;
    
    queue<int> todo;
    todo.push(v);
    
    while (!todo.empty()) {
        int next_v = todo.front();
        todo.pop();
        
        for (int x: G.at(next_v)) {
            if (depth.at(x) != -1) continue;
            depth.at(x) = depth.at(next_v) + 1;
            todo.push(x);
        }
    }
}

void chmax(int &a, int b) {
    if (a < b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    vector<int> depth(N, -1);
    dfs(G, 0, depth);

    int max_depth = 0, max_d_ind;
    for (int i = 0; i < N; i++) {
        if (max_depth < depth.at(i)) {
            max_depth = depth.at(i);
            max_d_ind = i;
        }
    }
    
    depth.assign(N, -1);
    dfs(G, max_d_ind, depth);

    int ans = 0;
    for (int d: depth) chmax(ans, d);
    cout << ans + 1 << endl;
} 