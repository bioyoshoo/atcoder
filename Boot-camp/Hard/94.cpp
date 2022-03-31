#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int64_t Comb(int64_t N, int64_t k) {
    vector<int64_t> table(N + 1, 1);
    for (int64_t i = 1; i <= N; i++) table.at(i) = i * table.at(i - 1) % mod;
    int64_t up = table.at(N), down = table.at(k) * table.at(N - k) % mod;

    int64_t inv = 1, a = down, n = mod - 2;
    while (n > 0) {
        if (n & 1) inv = inv * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    int64_t ans = up * inv % mod;
    return ans;
}

int main() {
    int64_t N, K;
    cin >> N >> K;

    for (int64_t i = 1; i <= K; i++) {
        int64_t ans = Comb(N - K + 1, i) * Comb(K - i, i - 1) % mod;
        cout << ans << endl;
    }
}