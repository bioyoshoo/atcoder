#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<pair<ll, ll>> C(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        C[i] = {a + b, a};
    }
    sort(C.rbegin(), C.rend());
    
    ll T = 0, A = 0;
    rep(i, N) {
        if (i % 2 == 0) T += C[i].second;
        else A += C[i].first - C[i].second;
    }
    cout << T - A << endl;
}