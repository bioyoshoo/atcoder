#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;

    ll n = 1;
    rep(i, M) n *= 2;
    ll ans = (1900 * M + 100 * (N - M)) * n;
    cout << ans << endl;
}