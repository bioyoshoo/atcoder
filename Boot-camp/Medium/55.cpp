#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int64_t>>;

bool search(const Graph &G, int64_t v, int64_t goal) {
    int64_t N = (int)G.size();

    vector<int> seen(N, -1);
    queue<int64_t> todo;

    seen.at(v) = 0;
    todo.push(v);
    
    while (!todo.empty()) {
        int64_t w = todo.front();
        todo.pop();
        if (seen.at(w) > 2) break;
        
        for (int64_t x: G.at(w)) {
            if (seen.at(x) != -1) continue;

            seen.at(x) = seen.at(w) + 1;
            todo.push(x);
        }
    }

    if (seen.at(goal) == 2) return true;
    else return false;
}

int main() {
    int64_t N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int64_t a, b;
        cin >> a >> b;
        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    if (search(G, 0, N - 1)) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
