#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    rep(i, N) {
<<<<<<< HEAD
        ll a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll c = N - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
        ans += a * c;
    }
    cout << ans << endl;
}
=======
        int a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        int c = N - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
        ans += 1LL*a*c;
    }

    cout << ans << endl;
}
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0