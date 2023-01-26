#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

ll dist[500][500], values[500][500];

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    vector<string> S(N); rep(i, N) cin >> S[i];
    
    // dist, values 初期化
    rep(i, N) rep(j, N) {
        if (i == j) dist[i][j] = 0;
        else if (S[i][j] == 'Y') dist[i][j] = 1;
        else if (S[i][j] == 'N') dist[i][j] = INF;
        
        if (S[i][j] == 'Y') values[i][j] = A[j];
        else values[i][j] = 0;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    values[i][j] = values[i][k] + values[k][j];
                }
                else if (dist[i][j] == dist[i][k] + dist[k][j]) {
                    if (values[i][j] < values[i][k] + values[k][j]) {
                        values[i][j] = values[i][k] + values[k][j];
                    }
                }
            }
        }
    }

    int Q; cin >> Q;
    rep(i, Q) {
        int u, v; cin >> u >> v; u--; v--;
        if (dist[u][v] == INF) cout << "Impossible" << endl;
        else cout << dist[u][v] << " " << values[u][v] + A[u] << endl;
    }
}   
