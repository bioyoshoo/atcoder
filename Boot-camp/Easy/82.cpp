#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll INF = 8e18;

int main() {
    ll Q, H, S, D; cin >> Q >> H >> S >> D;
    ll N; cin >> N;

    vector<ll> V_two = {8*Q, 4*H, 2*S, D};
    vector<ll> V_one = {4*Q, 2*H, S};
    ll min_two = INF, min_one = INF;
    
    rep(i, 4) min_two = min(min_two, V_two[i]);
    rep(i, 3) min_one = min(min_one, V_one[i]);

    ll ans = 0;
    ans += N / 2 * min_two;
    N %= 2;
    ans += N * min_one;
    cout << ans << endl;
}