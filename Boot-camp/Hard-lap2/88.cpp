#include <bits/stdc++.h>
using namespace std;

long long bit_cum(long long n) {
    long long res = 0;
    for (int i = 0; i < 50; i++) {
        long long cnt = 0;
        long long a = 1LL << (i + 1);
        long long loop = (n + 1) / a, residual = (n + 1) % a;
        cnt = a / 2 * loop + max(residual - a / 2, 0LL);
        if (cnt % 2 == 1) res += 1LL << i;
    }
    return res;
}

int main() {
    long long A, B;
    cin >> A >> B;
    long long ans;
    if (A == 0) ans = bit_cum(B);
    else ans = bit_cum(A - 1) ^ bit_cum(B);
    cout << ans << endl;
}