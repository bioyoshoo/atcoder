#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll GCD(ll A, ll B) {
    if (B == 0) return A;
    
    return GCD(B, A % B);
}

ll LCM(ll A, ll B) {
    ll g = GCD(A, B);
    return g * A / g * B / g;
}

int main() {
    ll A, B; cin >> A >> B;

    cout << LCM(A, B) << endl;
}