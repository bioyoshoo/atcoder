#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;
const ll INF = 1e18;

int N, K, M, S;
ll P, Q;
set<int> occupied, dangerous;

// 支配されている町から何回で到達できるか
vector<int> reach;
void BFS(const Graph &G) {
    queue<int> todo;
    for (auto o: occupied) todo.push(o);

    while (!todo.empty()) {
        int v = todo.front();
        todo.pop();

        for (auto nv: G[v]) {
            if (reach[nv] != -1) continue;
            reach[nv] = reach[v] + 1;
            todo.push(nv);
        }
    }
}

ll weight(int v) {
    if (v == N - 1) return 0;
    else if (occupied.count(v)) return INF;
    else if (dangerous.count(v)) return Q;
    return P;
}

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

vector<ll> dist;
void BFS2(const Graph &G, int s=0) {
    vector<bool> used(N);
    dist[s] = 0;
    
    // 探索
    rep(i, N) {
        int min_v = -1; ll min_dist = INF;
        rep(v, N) {
            if (!used[v] && min_dist > dist[v]) {
                min_dist = dist[v];
                min_v = v;
            }
        }

        if (min_v == -1) break;

        // 緩和
        for (auto nv: G[min_v]) {
            chmin(dist[nv], dist[min_v] + weight(nv));
        }
        used[min_v] = true;
    }
}

int main() {
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    rep(i, K) {
        int c; cin >> c; c--; occupied.insert(c);
    }
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    reach.assign(N, -1);
    rep(i, N) if (occupied.count(i)) reach[i] = 0;
    BFS(G);

    rep(i, N) {
        if (reach[i] > 0 && reach[i] <= S) dangerous.insert(i);
    }

    dist.assign(N, INF);
    BFS2(G, 0);

    cout << dist[N-1] << endl;
}
