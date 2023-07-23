#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i]; rep(i, N) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    ll ans = 0;
    rep(i, N) ans += 1LL * A[i] * B[i];
    cout << ans << endl;
}
