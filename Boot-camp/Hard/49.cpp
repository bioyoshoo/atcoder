#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;

    vector<int64_t> power2(32);
    power2.at(0) = 2;
    for (int i = 1; i < 31; i++) {
        power2.at(i + 1) = (power2.at(i) * power2.at(i)) % mod;
    }
    
    int64_t powe2_n;
    for (int64_t i = 0; (1LL << n))
}