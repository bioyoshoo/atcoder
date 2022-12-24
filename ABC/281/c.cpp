#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    for (int i = 1; i < N; i++) A[i] += A[i - 1];
    T %= A[N - 1];

    ll ans = -1, t = -1;
    for (int i = 1; i < N; i++) {
        if (A[i - 1] < T && T <= A[i]) {
            ans = i + 1;
            t = T - A[i - 1];
            break;
        }
    }

    if (ans == -1) {
        ans = 1; t = T;
    } 
    cout << ans << " " << t << endl;
}
