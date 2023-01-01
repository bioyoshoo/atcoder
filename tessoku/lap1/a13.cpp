#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    ll ans = 0;
    int R = 0;
    rep(L, N) {
        while ((R < N) && (abs(A[L] - A[R]) <= K)) R++;
        ans += R - L - 1;
    }

    cout << ans << endl;
}