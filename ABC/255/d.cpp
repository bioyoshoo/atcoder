#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> S = A;
    for (int i = 1; i < N; i++) S[i] += S[i - 1];

    rep(q, Q) {
        ll x; cin >> x;
        int i = lower_bound(A.begin(), A.end(), x) - A.begin();
        int j = upper_bound(A.begin(), A.end(), x) - A.begin();
        ll L = 0;
        if (i > 0) L = abs(S[i - 1] - x * i);
        ll R = 0;
        if (j > 0) R = S[N - 1] - S[j - 1] - x * (N - j);
        else R = S[N - 1] - x * (N - j);
        ll ans = L + R;
        cout << ans << endl;
    }
}