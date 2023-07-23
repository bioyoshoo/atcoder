#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    int Q; cin >> Q;
    rep(i, Q) {
        int x; cin >> x;
        auto idx = lower_bound(A.begin(), A.end(), x) - A.begin();

        cout << idx << endl;
    }
}