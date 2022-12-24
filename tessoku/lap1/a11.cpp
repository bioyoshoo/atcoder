#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N); rep(i, N) cin >> A[i];

    int ans = lower_bound(A.begin(), A.end(), X) - A.begin() + 1;
    cout << ans << endl;
}