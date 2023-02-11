#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll X = 0;
    int cnt = 0;
    int idx = -1;
    vector<vector<pair<int, ll>>> V(N);
    bool circle = false;
    while (true) {
        idx = X % N;
        V[idx].push_back(make_pair(cnt, X));

        if ((int)V[idx].size() == 2) {
            circle = true;
            break;
        }

        X += A[idx];
        cnt++;

        if (cnt == K) break;
    }
    
    if (!circle) {
        cout << X << endl;
        return 0;
    }

    ll T = V[idx][1].first - V[idx][0].first;
    ll sum = V[idx][1].second - V[idx][0].second;
    
    X = 0;
    for (ll i = 0; i < K;) {
        ll j = X % N;

        if (j == idx && (K - i) >= T) {
            ll lap = (K - i) / T;
            X += lap * sum;
            i += lap * T;
        }
        else {
            X += A[j];
            i++;
        }
    }

    cout << X << endl;
    return 0;
}
