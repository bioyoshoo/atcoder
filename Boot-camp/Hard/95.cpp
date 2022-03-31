#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 0, power = 1;
    for (int k = 0; k <= 60; k++) {
        int64_t x = 0;
        for (int64_t j = 0; j < N; j++) {
            if (A.at(j) & (1 << k)) x++;
        }
        int64_t now = x * (N - x) % mod;
        ans += now * power % mod;
        ans %= mod;
        power = power * 2 % mod;
    }

    cout << ans << endl;
}