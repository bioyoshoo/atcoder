#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];

    vector<int> ans;
    for (int i = K; i < N; i++) ans.push_back(A[i]);
    for (int i = 0; i < K; i++) ans.push_back(0);

    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}
