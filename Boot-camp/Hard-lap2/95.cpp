#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    long long ans = 0;
    for (int k = 0; k < 60; k++) {
        int a = 0;
        for (int i = 0; i < N; i++) if (A[i] & (1LL << k)) a++;
        long long ptn = a * (N - a) % mod;
        long long value = (1LL << k) % mod;
        ans += ptn * value % mod;
        ans %= mod;
    }
    cout << ans << endl;
}