#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;
const ll INF = 1e18;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(Edge(b, w));
        G[b].push_back(Edge(a, w));
    }

    vector<ll> dist(N, INF);
    vector<int> prev(N, -1);
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
                   
    while (!pq.empty()) {
        int v; ll d; tie(d, v) = pq.top();
        pq.pop();

        if (dist[v] < d) continue;

        for(auto e: G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                pq.push({dist[e.to], e.to});
                prev[e.to] = v;
            }
        }
    }

    vector<int> ans;
    int x = N - 1;
    while (prev[x] != -1) {
        ans.push_back(x);
        x = prev[x];
    }
    ans.push_back(x);
    reverse(ans.begin(), ans.end());

    for (auto a: ans) cout << a + 1 << " ";
    cout << endl;
}
