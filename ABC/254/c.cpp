#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<int>> V(K);
    for (int k = 0; k < K; k++) {
        for (int i = k; i < N; i += K) {
            V[k].push_back(A[i]);
        }
    }
    for (int i = 0; i < K; i++) sort(V[i].begin(), V[i].end());
    vector<int> ans(N);
    for (int k = 0; k < K; k++) {
        int n = V[k].size();
        for (int i = 0; i < n; i++) {
            ans[k + i * K] = V[k][i];
        }
    }
    bool flag = true;
    for (int i = 1; i < N; i++) if (ans[i - 1] > ans[i]) flag = false;
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}