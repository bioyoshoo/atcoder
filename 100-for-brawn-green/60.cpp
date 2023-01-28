#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;
const ll ERROR = 2e9;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int V, E; cin >> V >> E;

    vector<vector<ll>> dp(V, vector<ll>(V, INF));
    rep(i, V) dp[i][i] = 0;
    rep(i, E) {
        int s, t;
        ll d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    rep(k, V) {
        rep(i, V) {
            rep(j, V) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    bool negative_cycle = false;
    rep(v, V) if (dp[v][v] < 0) negative_cycle = true;

    if (negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        rep(i, V) {
            rep(j, V) {
                if (dp[i][j] > INF - ERROR) cout << "INF";
                else cout << dp[i][j];

                if (j == V - 1) cout << endl;
                else cout << " ";
            }
        }
    }
}