#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, P, Q, R, S; cin >> N >> P >> Q >> R >> S; P--; Q--; R--; S--;
    vector<int> A(N); rep(i, N) cin >> A[i];

    int n = Q - P;
    rep(i, n + 1) {
        swap(A[P + i], A[R + i]);
    }

    rep(i, N) cout << A[i] << " ";
    cout << endl;
}