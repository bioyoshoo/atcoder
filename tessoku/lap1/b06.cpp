#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N + 1); rep(i, N) cin >> A[i + 1];
    for (int i = 1; i <= N; i++) A[i] += A[i - 1];
    int Q; cin >> Q;
    rep(i, Q) {
        int L, R; cin >> L >> R;
        int win = A[R] - A[L - 1];
        int lose = (R - L + 1) - win;

        if (win > lose) cout << "win" << endl;
        else if (win == lose) cout << "draw" << endl;
        else cout << "lose" << endl;
    }
}
