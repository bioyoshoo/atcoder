#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll f(ll N) {
    return N / 4 - N / 100 + N / 400;
}

int main() {
    ll A, B;
    cin >> A >> B;

    ll ans = f(B) - f(A - 1);
    cout << ans << endl;
}