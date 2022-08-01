#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; ll C;
    cin >> N >> C;
    vector<int> T(N);
    vector<ll> A(N);
    rep(i, N) cin >> T[i] >> A[i];

    vector<ll> B(N);
    ll X = A[0];
    B[0] = A[0];
    for (int i = 1; i < N; i++) {
        if (T[i] == 1) X = X & A[i];
        else if (T[i] == 2) X = X | A[i];
        else if (T[i] == 2) X = X ^ A[i];
        B[i] = X;
    }

    ll ans = C;
    rep(i, N) {
        if (i == 0 && T[0] == 1) ans = ans & B[i];
        else if (i == 0 && T[0] == 2) ans = ans | B[i];
        else if (i == 0 && T[0] == 3) ans = ans ^ B[i];
        else if (i != 0 && T[0] == 3) ans = ans | B[i];
        cout << ans << endl;
    }
}