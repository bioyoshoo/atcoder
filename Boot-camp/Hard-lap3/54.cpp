#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    vector<ll> P(A), Q(B), R(C);
    rep(i, A) cin >> P[i];
    rep(i, B) cin >> Q[i];
    rep(i, C) cin >> R[i];
    sort(P.rbegin(), P.rend());
    sort(Q.rbegin(), Q.rend());
    sort(R.rbegin(), R.rend());

    vector<ll> S;
    rep(i, X) S.push_back(P[i]);
    rep(i, Y) S.push_back(Q[i]);
    rep(i, C) S.push_back(R[i]);
    sort(S.rbegin(), S.rend());

    ll ans = 0;
    rep(i, X + Y) ans += S[i];
    cout << ans << endl;
}