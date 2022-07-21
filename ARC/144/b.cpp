#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    ll a, b; cin >> N >> a >> b;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll bottom = 0, top = 1e18;
    while (top - bottom > 1) {
        ll x = bottom + (top - bottom) / 2;

        ll up = 0, down = 0;
        rep(i, N) {
            if (x > A[i]) up += ((x - A[i]) + a - 1) / a;
            if (x < A[i]) down += (A[i] - x) / b;
        }
        
        if (up <= down) bottom = x;
        else top = x;
    }
    
    ll up = 0, down = 0;
    rep(i, N) {
        if (bottom > A[i]) up += ((bottom - A[i]) + a - 1) / a;
        if (bottom < A[i]) down += (A[i] - bottom) / b;
    }
    sort(A.begin(), A.end());
    
    
    cout << bottom << endl;
}