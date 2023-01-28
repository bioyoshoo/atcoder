#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N + 1);
    rep(i, N) cin >> A[i + 1];

    for (int i = 1; i < N + 1; i++) A[i] += A[i - 1];

    for (int k = 1; k <= N; k++) {
        ll ans = 0;
        for (int i = 0; i < N + 1; i++) {
            if (i + k >= N + 1) continue;
            ans = max(ans, A[i + k] - A[i]);
        }

        cout << ans << endl;
    }
}
