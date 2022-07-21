#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    rep(i, N) rep(j, M) cin >> A[i][j];

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            ll sum = 0;
            rep(x, N) sum += max(A[x][i], A[x][j]);
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}