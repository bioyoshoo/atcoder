#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> ans(N);
    ll x = 0;
    //cout << "hre" << endl;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) x += A[i];
        else x -= A[i];
    }
    ans[0] = x;
    for (int i = 0; i < N - 1; i++) ans[i + 1] = 2 * A[i] - ans[i];
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}