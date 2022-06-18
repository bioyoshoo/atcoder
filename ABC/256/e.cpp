#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> X(N);
    rep(i, N) {
        cin >> X[i];
        X[i]--;
    }
    vector<int> C(N); rep(i, N) cin >> C[i];

    ll ans = 0;
    rep(i, N) if (i == X[X[i]] && C[i] < C[X[i]]) ans += C[i];
    cout << ans << endl;
}