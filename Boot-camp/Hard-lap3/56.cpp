#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    ll plus = 0, minus = 0;
    rep(i, N) {
        if (A[i] < B[i]) plus += (B[i] - A[i]) / 2;
        else if (A[i] > B[i]) minus += A[i] - B[i];
    }
    if (plus >= minus) cout << "Yes" << endl;
    else cout << "No" << endl;
}