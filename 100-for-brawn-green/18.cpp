#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    int q; cin >> q;
    vector<ll> T(q); rep(i, q) cin >> T[i];
    
    sort(A.begin(), A.end());
    int ans = 0;
    rep(i, q) {
        int a = lower_bound(A.begin(), A.end(), T[i]) - A.begin();
        int b = upper_bound(A.begin(), A.end(), T[i]) - A.begin();
        if (a != b) ans++;
    }
    cout << ans << endl;
}