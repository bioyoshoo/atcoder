#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    rep(i, N) A[i] -= i + 1;
    sort(A.begin(), A.end());

    ll cand1 = 0;
    rep(i, N) cand1 += abs(A[i] - A[N / 2]);
    ll cand2 = 0;
    rep(i, N) cand2 += abs(A[i] - A[N / 2 + 1]);
    cout << min(cand1, cand2) << endl;
}