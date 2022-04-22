#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int64_t P(int64_t n, int64_t k) {
    int64_t res = 1;
    for (int64_t i = n; i > n - k; i--) res = res * i % mod;
    return res;
}

int main() {
    int64_t N, M;
    cin >> N >> M;
    if (N > M) swap(N, M);

    int64_t ans;
    if (M - N > 1) ans = 0;
    else {
        int64_t M_dist = P(M, M);
        int64_t N_dist = P(N, M - 1);
        
        if (N == M) ans = (M_dist * N_dist % mod) * 2 % mod;
        else if (M - N == 1) ans = M_dist * N_dist % mod;
    }

    cout << ans << endl;
}