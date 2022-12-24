#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    vector<int> L(N), R(N);
    L[0] = A[0]; R[N - 1] = A[N - 1];
    
    for (int i = 1; i < N; i++) L[i] = max(A[i], L[i - 1]);
    for (int i = N - 2; i >= 0; i--) R[i] = max(A[i], R[i + 1]);

    int D; cin >> D;
    rep(i, D) {
        int l, r; cin >> l >> r; l--; r--;
        cout << max(L[l - 1], R[r + 1]) << endl;
    }
}
