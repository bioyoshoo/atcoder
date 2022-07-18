#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<ll> H(N); rep(i, N) cin >> H[i];
    sort(H.begin(), H.end());

    ll ans = 1e15;
    rep(i, N) {
        if (i + K - 1 < N) {
            ll cand = H[i + K - 1] - H[i];
            ans = min(ans, cand);
        }
    }
    cout << ans << endl;
}