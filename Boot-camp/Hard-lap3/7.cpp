#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    
    vector<pair<ll, ll>> V;
    rep(i, M) {
        ll b, c; cin >> b >> c;
        V.push_back({c, b});
    }
    sort(V.rbegin(), V.rend());

    priority_queue<ll> pq;
    for (int i = 0; i < M; i++) {
        ll b, c; tie(c, b) = V[i];
        for (int j = 0; j < b; j++) pq.push(c);
        if (pq.size() > N) break;
    }

    ll ans = 0;
    rep(i, N) {
        if (!pq.empty() && pq.top() > A[i]) {
            ans += pq.top();
            pq.pop();
        }
        else ans += A[i];
    }
    cout << ans << endl;
}