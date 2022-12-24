#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    vector<ll> T;
    rep(i, M) T.push_back(A[i]);

    ll ans = 0;
    rep(i, K) ans += T[i];
    cout << ans << " ";

    if (M == K) {
        for (int i = 1; i < N - M + 1; i++) {
            ans -= A[i - 1]; ans += A[i + M - 1];
            cout << ans << " ";
        }
    }

    
    // else {

    // }
}