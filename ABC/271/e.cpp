#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 1e18;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> A(M), B(M), C(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
    }
    vector<int> E(K);
    rep(i, K) {
        cin >> E[i];
        E[i]--;
    }

    vector<ll> dp(N, INF);
    dp[0] = 0;

    rep(i, K) {
        chmin(dp[B[E[i]]], dp[A[E[i]]] + C[E[i]]);
    }

    if (dp[N - 1] < INF) cout << dp[N - 1] << endl;
    else cout << -1 << endl;
}