#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> C(N - 1), S(N - 1), F(N - 1);
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];

    vector<ll> ans(N);
    rep(s, N - 1) {
        ll t = 0;
        for (int i = s; i < N - 1; i++) {
            // arrive i th station
            ll left;
            if (t <= S[i]) left = S[i];
            else left = S[i] + (t - S[i] + F[i] - 1) / F[i] * F[i];
            t = left + C[i];
        }
        ans[s] = t;
    }
    rep(i, N) cout << ans[i] << endl;
}