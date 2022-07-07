#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

int main() {
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    mint ans = 0;
    for (ll i = 0; i <= 60; i++) {
        ll cnt = 0;
        rep(j, N) {
            if (A[j] & (1LL << i)) cnt++;
        }
        mint num = cnt * (N - cnt);
        ans += num * (1LL << i);
    }
    cout << ans.val() << endl;
}