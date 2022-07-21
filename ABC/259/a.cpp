#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M, X, T, D; cin >> N >> M >> X >> T >> D;

    ll ans;
    if (X <= M && X <= N) ans = T;
    else {
        ans = T - (X - M) *  D;
    }
    cout << ans << endl;
}