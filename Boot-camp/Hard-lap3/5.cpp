#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M; cin >> N >> M;
    priority_queue<ll> pq;
    rep(i, N) {
        ll a; cin >> a; pq.push(a);
    }

    for (int i = 0; i < M; i++) {
        ll a = pq.top();
        pq.pop();
        a /= 2;
        pq.push(a);
    }
    ll ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}