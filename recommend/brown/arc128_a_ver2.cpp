#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<int> exchange(N);
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > A[i + 1]) exchange[i] = 1;
        else exchange[i] = 0;
    }
    vector<int> ans(N);
    ans[0] = exchange[0];
    for (int i = 1; i < N; i++) {
        if (exchange[i - 1] != exchange[i]) ans[i] = 1;
    }
    for (auto a: ans) cout << a << " ";
    cout << endl;
}