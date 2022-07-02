#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    vector<ll> V(3);
    rep(i, 3) cin >> V[i];
    sort(V.begin(), V.end());

    ll ans = 0;
    ans += V[0];
    V[2] -= V[0];

    ans += V[1];
    V[2] -= V[1];

    if (V[2] == 0) cout << ans << endl;
    else cout << -1 << endl;
}