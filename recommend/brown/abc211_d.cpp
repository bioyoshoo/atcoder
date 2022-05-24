#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;
const ll INF = 1e15;

vector<ll> len;
vector<ll> path;
void BFS(const Graph &G, int v = 0) {
    len[v] = 0;
    path[v] = 1;
    queue<int> todo;
    todo.push(v);
    while (!todo.empty()) {
        int w = todo.front();
        todo.pop();
        for (auto next_v: G[w]) {
            if (next_v == w) continue;
            if (len[next_v] < len[w] + 1) continue;
            
            if (len[next_v] > len[w] + 1) {
                path[next_v] = path[w];
                len[next_v] = len[w] + 1;
                todo.push(next_v);
            }
            else if (len[next_v] == len[w] + 1) path[next_v] += path[w];
            path[next_v] %= mod;
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    len.assign(N, INF);
    path.assign(N, 0);
    BFS(G);
    cout << path[N - 1] << endl;
}