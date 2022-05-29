#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N; cin >> N;
    
    ll ans;
    if (N % 2 == 1) ans = 0;
    else {
        ans = 0;
        ll n = 2;
        while (n < N) {
            n *= 5;
            ans += N / n;
        }
    }
    cout << ans << endl;
}