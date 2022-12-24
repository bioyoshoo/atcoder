#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> S(N), ans(N);
    rep(i, N) cin >> S[i];

    ans[0] = S[0];
    for (int i = 1; i < N; i++) {
        ans[i] = S[i] - S[i - 1];
    }

    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}