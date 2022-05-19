#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const ll mod = 1e9 + 7;
using mat = vector<vector<ll>>;
#define rep(i, n) for (int i = 0; i < (n); i++)

mat matmal(mat A, mat B) {
    mat res(A.size(), vector<ll>(B[0].size()));
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)B[0].size(); j++) {
            for (int k = 0; k < (int)B.size(); k++) {
                res[i][j] += A[i][k] * B[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

mat matpow(mat A, ll n) {
    mat res(A.size(), vector<ll>(A[0].size()));
    for (int i = 0; i < (int)A.size(); i++) res[i][i] = 1;
    while (n > 0) {
        if (n & 1) res = matmal(res, A);
        A = matmal(A, A);
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, K; cin >> N >> K;
    mat A(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    mat dp = matpow(A, K);
    ll ans = 0;
    rep(i, N) rep(j, N) ans += dp[i][j] % mod; ans %= mod;
    cout << ans << endl;
}