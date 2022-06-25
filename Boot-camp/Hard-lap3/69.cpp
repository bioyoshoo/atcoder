#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll ans = 0;
    rep(r, 2) {
        if (r == 0) sort(A.begin(), A.end());
        else sort(A.rbegin(), A.rend());

        vector<ll> T;
        int i = 0, j = N - 1;
        while (i <= j) {
            T.push_back(A[i]); i++;
            T.push_back(A[j]); j--;
        }
        ll sum = 0, min_d = 1e10;
        rep(i, N) {
            ll d = abs(T[i] - T[(i + 1) % N]);
            sum += d;
            min_d = min(min_d, d);
        }
        ans = max(ans, sum - min_d);
    }
    cout << ans << endl;
}