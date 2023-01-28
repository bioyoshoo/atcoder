#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int D, N; cin >> D >> N;
    vector<int> A(D + 1);

    rep(i, N) {
        int l, r; cin >> l >> r; l--; r--;
        A[l] += 1; A[r + 1] += -1;
    }

    for (int i = 1; i < D + 1; i++) A[i] += A[i - 1];

    rep(i, D) cout << A[i] << endl;
}