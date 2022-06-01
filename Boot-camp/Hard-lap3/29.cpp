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
    sort(A.begin(), A.end());

    ll idx = -1;
    ll sum = 0;
    rep(i, N - 1) {
        sum += A[i];
        if (2 * sum < A[i + 1]) idx = i;
    }
    ll ans = N - idx - 1;
    cout << ans << endl;
}