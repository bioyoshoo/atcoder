#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int D; cin >> D;
    int X; cin >> X;
    vector<int> A(D); for (int i = 1; i < D; i++) cin >> A[i];
    A[0] = X;
    for (int i = 1; i < D; i++) A[i] += A[i - 1];

    int Q; cin >> Q;
    rep(i, Q) {
        int s, t; cin >> s >> t; s--; t--;

        if (A[s] > A[t]) cout << s + 1 << endl;
        else if (A[s] < A[t]) cout << t + 1 << endl;
        else cout << "Same" << endl;
    }
}
