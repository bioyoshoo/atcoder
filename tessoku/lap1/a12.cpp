#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];
    
    ll L = 0, R = 1e9;
    while (L < R) {
        ll x = (L + R) / 2;

        ll cnt = 0;
        rep(i, N) cnt += x / A[i];

        if (cnt >= K) R = x;
        else L = x + 1;
    }
    cout << R << endl;
}
