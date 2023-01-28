#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); rep(i, N) cin >> A[i];
    for (int i = 1; i < N; i++) A[i] += A[i - 1];

    rep(i, Q) {
        int l, r; cin >> l >> r; l--; r--;
        cout << A[r] - A[l - 1] << endl;
    }
}
