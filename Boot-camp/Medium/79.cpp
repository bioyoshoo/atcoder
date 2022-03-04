#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int64_t factorial_mod(int64_t n) {
    int64_t ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

int main() {
    int64_t N, M;
    cin >> N >> M;

    if (N > M) swap(N, M);

    if (M - N > 1) cout << 0 << endl;
    else cout << (((factorial_mod(N) * factorial_mod(M)) % mod) * (2 - (M - N))) % mod << endl;
}