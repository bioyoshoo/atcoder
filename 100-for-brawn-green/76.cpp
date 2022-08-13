#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    vector<ll> C(N + 1);
    for (int i = 1; i < N + 1; i++) C[i] = A[i - 1] + C[i - 1];

    for (int k = 1; k <= N; k++) {
        ll ans = 0;
        rep(s, N + 1) {
            if (s + k > N) continue;
            ans = max(ans, C[s + k] - C[s]);
        }
        cout << ans << endl;
    }
}