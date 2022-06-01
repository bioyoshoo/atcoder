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
    int n; cin >> n;
    vector<ll> A(n);
    ll a_max = -1;
    rep(i, n) {
        ll a; cin >> a;
        a_max = max(a_max, a);
        A[i] = a;
    }
    ll a_nex, dist = 1e10;
    rep(i, n) {
        if (a_max == A[i]) continue;
        if (chmin(dist, abs(A[i] - a_max / 2))) a_nex = A[i];
    }
    cout << a_max << " " << a_nex << endl;
}