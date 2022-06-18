#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> S(N + 1);
    for (int i = 1; i < N + 1; i++) S[i] = A[i - 1] + S[i - 1];
    map<ll, ll> mp;
    rep(i, N + 1) mp[S[i]]++;
    ll ans = 0;
    for (auto m: mp) ans += m.second * (m.second - 1) / 2;
    cout << ans << endl;
}