#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    mint ans = 1;
    vector<int> D(N + 1);
    D[0] = 3;

    rep(i, N) {
        ans *= D[A[i]];

        D[A[i]]--;
        D[A[i] + 1]++;
    }

    cout << ans.val() << endl;
}