#include <bits/stdc++.h>
using namespace std;

vector<long long> Erasto(long long N) {
    vector<long long> res;
    vector<bool> isprime(N + 1, true);
    isprime[0] = false;
    isprime[1] = false;

    for (long long p = 2; p <= N; p++) {
        if (!isprime[p]) continue;
        for (long long q = 2 * p; q <= N; q += p) {
            isprime[q] = false;
        }
    }
    for (long long i = 2; i <= N; i++) {
        if (isprime[i]) res.push_back(i);
    }
    return res;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> res = Erasto(1e6);
    long long size = res.size();

    long long ans = 0;
    for (long long i = 0; i < size; i++) {
        long long p = res[i];
        if (p >= 1e5) break;
        
        for (long long j = i + 1; j < size; j++) {
            long long q = res[j];
            if (p > 1e18 / (q * q * q)) break;

            long long cand = p * q * q * q;
            if (1 <= cand && cand <= N) ans++;
        }
    }
    cout << ans << endl;
}