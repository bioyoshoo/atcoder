#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll A, B; cin >> A >> B;

    ll ans = 0;
    while (A != B) {
        if (A < B) swap(A, B);

        if (A % B == 0) {
            ans += A / gcd(A, B) - 1;
            break;
        }
        else if (B == 1) {
            ans += A - 1;
            break;
        }
        else {
            ans += A / B;
            A %= B;
        }
    }

    cout << ans << endl;
}