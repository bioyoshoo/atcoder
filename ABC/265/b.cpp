#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M, T; cin >> N >> M >> T;
    vector<ll> A(N - 1);
    rep(i, N - 1) cin >> A[i];
    map<ll, ll> mp;
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--;
        mp[x] = y;
    }

    bool ans = true;
    ll t = T;
    for (int i = 0; i < N - 1; i++) {
        t += mp[i];
        if (t <= A[i]) {
            ans = false;
            break;
        }
        t -= A[i];
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}