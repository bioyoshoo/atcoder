#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<int> C(Q + 2);
    rep(i, Q) {
        cin >> C[i + 1];
        C[i + 1]--;
    }
    C[0] = 0; C[Q + 1] = 0;

    vector<ll> V(N);
    for (int i = 1; i < N; i++) V[i] = modpow(A[i - 1], A[i]);
    for (int i = 1; i < N; i++) V[i] = V[i] + V[i - 1] % mod;

    ll ans = 0;
    for (int i = 1; i < Q + 2; i++) {
        ans += V[max(C[i - 1], C[i])] - V[min(C[i - 1], C[i])] % mod;
        ans %= mod;
    }

    cout << ans << endl;
}
