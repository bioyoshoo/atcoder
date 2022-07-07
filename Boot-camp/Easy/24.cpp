#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int a, b, m; cin >> a >> b >> m;
    vector<ll> A(a), B(b);
    
    ll min_ref = 1e10;
    rep(i, a) {
        cin >> A[i];
        chmin(min_ref, A[i]);
    }
    ll min_micro = 1e10;
    rep(i, b) {
        cin >> B[i];
        chmin(min_micro, B[i]);
    }
    ll ans = min_ref + min_micro;

    rep(i, m) {
        int x, y, c; cin >> x >> y >> c; x--; y--;
        chmin(ans, A[x] + B[y] - c);
    }
    cout << ans << endl;
} 