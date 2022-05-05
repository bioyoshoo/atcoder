#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<long long> table;
long long Comb(long long n, long long k, long long mod) {
    if (n < k) return 0;
    long long X = table[n], Y = table[n - k] * table[k] % mod;
    return X * modpow(Y, mod - 2, mod) % mod;
}

int main() {
    long long N, K;
    cin >> N >> K;
    table.resize(N + 1);
    table[0] = 1;
    for (long long n = 1; n <= N; n++) table[n] = n;
    for (long long n = 2; n <= N; n++) table[n] = table[n] * table[n - 1] % mod;
    
    vector<long long> ans(K + 1);
    for (long long k = 1; k <= K; k++) {
        long long partition = Comb(K - 1, k - 1, mod);
        long long choice = Comb(N - K + 1, k, mod);
        ans[k] = partition * choice % mod;
    }

    for (int k = 1; k <= K; k++) cout << ans[k] << endl;
}