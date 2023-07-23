#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N); rep(i, N) cin >> A[i];

    if (X == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    set<int> W;
    rep(i, N) {
        if (W.count(A[i])) {
            cout << "Yes" << endl;
            return 0;
        }
        else {
            W.insert(A[i] + X);
            W.insert(A[i] - X);
        }
    }

    cout << "No" << endl;
    return 0;
}