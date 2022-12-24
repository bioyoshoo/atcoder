#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    
    vector<int> C = A;
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());

    vector<int> B(N);
    rep(i, N) {
        B[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
    }

    rep(i, N) cout << B[i] + 1 << " ";
    cout << endl;
}
