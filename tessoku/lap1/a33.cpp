#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll sum = 0;
    rep(i, N) sum ^= A[i];

    if (sum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}