#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, x; cin >> N >> x;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll ans = 0;
    rep(i, N - 1) {
        ll n = max(0LL, (A[i] + A[i + 1]) - x);
        ans += n;
        if (n <= A[i + 1]) A[i + 1] = A[i + 1] - n;
        else {
            A[i] = n - A[i + 1];
            A[i + 1] = 0;
        }
    }
    cout << ans << endl;
}